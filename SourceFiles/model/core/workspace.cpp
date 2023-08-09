#include "core/workspace.h"

#include <stdexcept>

namespace CommunalCalculator::Core {

auto Workspace::GetUserHomePath() -> std::filesystem::path {
  throw std::runtime_error("Workspace::GetUserHomePath: no implementation");
}

}  // namespace CommunalCalculator::Core
