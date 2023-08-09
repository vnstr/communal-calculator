#ifndef SOURCEFILES_MODEL_CORE_WORKSPACE_H_
#define SOURCEFILES_MODEL_CORE_WORKSPACE_H_

#include <filesystem>

namespace CommunalCalculator::Core {

class Workspace {
 public:
  Workspace() = default;
  Workspace(const Workspace &) = default;
  Workspace(Workspace &&) = default;

  auto operator=(const Workspace &) -> Workspace & = default;
  auto operator=(Workspace &&) -> Workspace & = default;

  virtual ~Workspace() = default;

  virtual auto GetUserHomePath() -> std::filesystem::path;
};

}  // namespace CommunalCalculator::Core

#endif  // SOURCEFILES_MODEL_CORE_WORKSPACE_H_
