#ifndef SOURCEFILES_MODEL_CORE_MODEL_H_
#define SOURCEFILES_MODEL_CORE_MODEL_H_

#include <memory>
#include <string>

#include "core/app_configuration.h"
#include "core/calculator.h"
#include "core/communal_counter.h"
#include "core/observer.h"

namespace CommunalCalculator::Core {

namespace Test {
class ModelMock;
}

class Model {
 public:
  struct Calculation {
    float result{0};
    std::string log;
  };

  Model() = default;
  Model(const Model &) = delete;
  Model(Model &&) = delete;

  auto operator=(const Model &) -> Model & = delete;
  auto operator=(Model &&) -> Model & = delete;

  virtual ~Model() = default;

  // Observers:
  Observer<Calculation> calculationResultObserver_;
  Observer<AppConfiguration> appConfigurationObserver_;
  // ---------------------------------------------------------------------------

  virtual void CalculateSummary(Calculator::CommunalCounters &&counters);

 private:
  friend Test::ModelMock;

  virtual void Calculate(Calculator &calculator,
                         const Calculator::CommunalCounters &counters);
};

}  // namespace CommunalCalculator::Core

#endif  // SOURCEFILES_MODEL_CORE_MODEL_H_
