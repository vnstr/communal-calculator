#ifndef TESTS_SOURCEFILES_CORE_MODEL_TEST_H_
#define TESTS_SOURCEFILES_CORE_MODEL_TEST_H_

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <memory>
#include <utility>

#include "core/calculator_test.h"
#include "core/model.h"

namespace CommunalCalculator::Core::Test {

class ModelMock;

class ModelTest : public ::testing::Test {
 public:
  void SetUp() override { modelMock_ = std::make_unique<ModelMock>(); }

  std::unique_ptr<ModelMock> modelMock_;
  CalculatorMock calculatorMock_;
};

class ModelMock : public Core::Model {
 public:
  MOCK_METHOD(void, CalculateSummary,
              (Calculator::CommunalCounters && counters), (override));
  void RealCalculateSummary(Calculator::CommunalCounters &&counters) {
    Core::Model::CalculateSummary(std::move(counters));
  }

  MOCK_METHOD(void, Calculate,
              (Calculator & calculator,
               const Calculator::CommunalCounters &counters),
              (override));
  void RealCalculate(Calculator &calculator,
                     const Calculator::CommunalCounters &counters) {
    Core::Model::Calculate(calculator, counters);
  }
};

}  // namespace CommunalCalculator::Core::Test

#endif  // TESTS_SOURCEFILES_CORE_MODEL_TEST_H_
