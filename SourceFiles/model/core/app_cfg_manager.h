#ifndef SOURCEFILES_MODEL_CORE_APP_CFG_MANAGER_H_
#define SOURCEFILES_MODEL_CORE_APP_CFG_MANAGER_H_

#include <memory>

#include "core/app_configuration.h"

namespace CommunalCalculator::Core {

class AppCfgManager {
 public:
  AppCfgManager() = default;
  AppCfgManager(const AppCfgManager &) = default;
  AppCfgManager(AppCfgManager &&) = default;

  auto operator=(const AppCfgManager &) -> AppCfgManager & = default;
  auto operator=(AppCfgManager &&) -> AppCfgManager & = default;

  virtual ~AppCfgManager() = default;

  [[nodiscard]] virtual auto GetCfg() -> std::shared_ptr<AppConfiguration>;
  virtual void SaveCfg(const std::shared_ptr<AppConfiguration> &cfg);
};

}  // namespace CommunalCalculator::Core

#endif  // SOURCEFILES_MODEL_CORE_APP_CFG_MANAGER_H_
