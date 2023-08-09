#include "model_view/model_view.h"

#include <cassert>
#include <utility>

#include "core/communal_counter.h"

namespace CommunalCalculator {

void ModelView::ConnectModel(const std::shared_ptr<Core::Model> &model_view) {
  model_ = model_view;
  assert(model_);

  auto on_calculation = [weak_self = weak_from_this()]() {
    auto self = weak_self.lock();
    if (!self) {
      return;
    }

    auto calculation = self->model_->calculationResultObserver_.PullCopy();

    QMap<QString, QVariant> calculation_map;
    calculation_map.insert("result", calculation.result);
    calculation_map.insert("log", QString(calculation.log.c_str()));

    self->EmitSummaryCalculated(calculation_map);
  };

  model_->calculationResultObserver_.SetConnection(std::move(on_calculation));
}

void ModelView::onCalculateSummary(const QMap<QString, QVariant> &values) {
  constexpr auto kColdWaterType = Core::CommunalCounter::Type::kColdWater;
  constexpr auto kHotWaterType = Core::CommunalCounter::Type::kHotWater;
  constexpr auto kT1Type = Core::CommunalCounter::Type::kElectricityT1;
  constexpr auto kT2Type = Core::CommunalCounter::Type::kElectricityT2;
  constexpr auto kT3Type = Core::CommunalCounter::Type::kElectricityT3;

  auto get_float = [&values](const char *key) -> float {
    auto found = values.find(key);
    if (found != values.cend()) {
      const auto &variant = found.value();
      if (variant.canConvert<float>()) {
        return variant.toFloat();
      }
    }
    return 0;
  };

  auto cold_water = CreatCommunalCounter(kColdWaterType);
  cold_water->SetPrevValue(get_float("coldWaterPrev"));
  cold_water->SetCurValue(get_float("coldWaterCur"));

  auto hot_water = CreatCommunalCounter(kHotWaterType);
  hot_water->SetPrevValue(get_float("hotWaterPrev"));
  hot_water->SetCurValue(get_float("hotWaterCur"));

  auto electricity_t1 = CreatCommunalCounter(kT1Type);
  electricity_t1->SetPrevValue(get_float("T1Prev"));
  electricity_t1->SetCurValue(get_float("T1Cur"));

  auto electricity_t2 = CreatCommunalCounter(kT2Type);
  electricity_t2->SetPrevValue(get_float("T2Prev"));
  electricity_t2->SetCurValue(get_float("T2Cur"));

  auto electricity_t3 = CreatCommunalCounter(kT3Type);
  electricity_t3->SetPrevValue(get_float("T3Prev"));
  electricity_t3->SetCurValue(get_float("T3Cur"));

  // TODO(Vostrilov):
  //  getting tariffs by model->GetAppConfig(...)
  //  calculating by model->CalculateSummary(...)

  Core::Calculator::CommunalCounters communal_counters = {
      {kColdWaterType, std::move(cold_water)},
      {kHotWaterType, std::move(hot_water)},
      {kT1Type, std::move(electricity_t1)},
      {kT2Type, std::move(electricity_t2)},
      {kT3Type, std::move(electricity_t3)}};

  model_->CalculateSummary(std::move(communal_counters));
}

auto ModelView::CreatCommunalCounter(Core::CommunalCounter::Type type)
    -> std::shared_ptr<Core::CommunalCounter> {
  return std::make_shared<Core::CommunalCounter>(type);
}

void ModelView::EmitSummaryCalculated(const QMap<QString, QVariant> &result) {
  emit summaryCalculated(result);
}

}  // namespace CommunalCalculator
