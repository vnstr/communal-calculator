#ifndef SOURCEFILES_MODEL_CORE_MODEL_H_
#define SOURCEFILES_MODEL_CORE_MODEL_H_

namespace CommunalCalculator::Core {

class Model {
 public:
  Model() = default;
  Model(const Model &) = delete;
  Model(Model &&) = delete;

  auto operator=(const Model &) -> Model & = delete;
  auto operator=(Model &&) -> Model & = delete;

  virtual ~Model() = default;
};

}  // namespace CommunalCalculator::Core

#endif  // SOURCEFILES_MODEL_CORE_MODEL_H_
