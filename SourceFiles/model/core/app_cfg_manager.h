#ifndef SOURCEFILES_MODEL_CORE_APP_CFG_MANAGER_H_
#define SOURCEFILES_MODEL_CORE_APP_CFG_MANAGER_H_

#include <filesystem>
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

  virtual void SetDirPath(const std::filesystem::path &dir_path);
  [[nodiscard]] virtual auto GetDirPath() const
      -> const std::filesystem::path &;

  [[nodiscard]] virtual auto GetCfg() -> std::shared_ptr<AppConfiguration>;
  virtual void SaveCfg(const std::shared_ptr<AppConfiguration> &cfg);

 private:
  static constexpr char const *kCfgFilename = ".communal_calculator";

  std::filesystem::path dirPath_;
};

}  // namespace CommunalCalculator::Core

#endif  // SOURCEFILES_MODEL_CORE_APP_CFG_MANAGER_H_
