#include "core/model.h"

#include <stdexcept>
#include <utility>

namespace CommunalCalculator::Core {

void Model::CalculateSummary(Calculator::CommunalCounters &&counters) {
  Calculator calculator;
  Calculate(calculator, counters);
}

void Model::Calculate(Calculator &calculator,
                      const Calculator::CommunalCounters &counters) {
  for (const auto &counter_it : counters) {
    calculator.SetCounter(counter_it.second);
  }

  auto app_cfg = appConfigurationObserver_.PullCopy();
  auto water_sink_tariff = app_cfg.GetWaterSinkTariff();

  calculator.SetWaterSinkTariff(water_sink_tariff);

  Calculation calculation;
  calculation.result = calculator.CalculateSummary(&calculation.log);

  calculationResultObserver_.Push(std::move(calculation));
}

}  // namespace CommunalCalculator::Core
