#include "core/model_test.h"

namespace CommunalCalculator::Core::Test {

TEST_F(ModelTest, CalculateSummaryPassingArgs) {
  Calculator::CommunalCounters communal_counters = {
      {CommunalCounter::Type::kColdWater, {}},
      {CommunalCounter::Type::kElectricityT1, {}}};

  EXPECT_CALL(*modelMock_, Calculate(::testing::_, communal_counters));

  auto communal_counters_copy = communal_counters;
  modelMock_->RealCalculateSummary(std::move(communal_counters_copy));
}

TEST_F(ModelTest, CalculatePassingArgs) {
  constexpr float kWaterSinkTariff = 2;

  auto hot_water = CalculatorTest::CreateCommunalCounterMock();
  auto cold_water = CalculatorTest::CreateCommunalCounterMock();

  Calculator::CommunalCounters communal_counters = {
      {CommunalCounter::Type::kColdWater, cold_water},
      {CommunalCounter::Type::kHotWater, hot_water}};

  EXPECT_CALL(calculatorMock_, SetCounter(::testing::Eq(cold_water)));
  EXPECT_CALL(calculatorMock_, SetCounter(::testing::Eq(hot_water)));
  EXPECT_CALL(calculatorMock_, SetWaterSinkTariff(kWaterSinkTariff));
  EXPECT_CALL(calculatorMock_, CalculateSummary);

  auto app_cfg = modelMock_->appConfigurationObserver_.PullCopy();
  app_cfg.SetWaterSinkTariff(kWaterSinkTariff);
  modelMock_->appConfigurationObserver_.Push(app_cfg);

  modelMock_->RealCalculate(calculatorMock_, communal_counters);
}

TEST_F(ModelTest, CalculateNotifyObserver) {
  constexpr float kResult = 100;
  constexpr char const *kCalculationLog = "(calculation log)";

  Calculator::CommunalCounters communal_counters = {
      {CommunalCounter::Type::kColdWater, {}},
      {CommunalCounter::Type::kHotWater, {}}};

  EXPECT_CALL(calculatorMock_, SetCounter).Times(2);
  EXPECT_CALL(calculatorMock_, SetWaterSinkTariff);

  auto calculate_summary = [](std::string *out_log) -> float {
    assert(out_log != nullptr);
    *out_log = "(calculation log)";
    return kResult;
  };

  EXPECT_CALL(calculatorMock_, CalculateSummary)
      .WillOnce(::testing::Invoke(calculate_summary));

  bool connection_called = false;
  Model::Calculation calculation;

  auto connection = [&connection_called, &calculation, this]() {
    connection_called = true;
    calculation = modelMock_->calculationResultObserver_.PullCopy();
  };

  modelMock_->calculationResultObserver_.SetConnection(std::move(connection));
  modelMock_->RealCalculate(calculatorMock_, communal_counters);

  ASSERT_TRUE(connection_called);
  EXPECT_EQ(kResult, calculation.result);
  EXPECT_EQ(kCalculationLog, calculation.log);
}

}  // namespace CommunalCalculator::Core::Test
