#include "core/app_cfg_manager.h"

#include <stdexcept>

namespace CommunalCalculator::Core {

void AppCfgManager::SetDirPath(const std::filesystem::path &dir_path) {
  dirPath_ = dir_path;
}

auto AppCfgManager::GetDirPath() const -> const std::filesystem::path & {
  return dirPath_;
}

auto AppCfgManager::GetCfg() -> std::shared_ptr<AppConfiguration> {
  throw std::runtime_error("AppCfgManager::GetCfg: no implementation");
}

void AppCfgManager::SaveCfg(const std::shared_ptr<AppConfiguration> &cfg) {
  throw std::runtime_error("AppCfgManager::GetCfg: no implementation");
}

}  // namespace CommunalCalculator::Core
