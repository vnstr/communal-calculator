#ifndef SOURCEFILES_MODEL_CORE_APP_CFG_MANAGER_H_
#define SOURCEFILES_MODEL_CORE_APP_CFG_MANAGER_H_

#include <filesystem>
#include <memory>

#include "core/app_configuration.h"
#include "wrappers/std_of_stream_wrapper.h"

namespace CommunalCalculator::Core {

namespace Test {
class AppCfgManagerMock;
}

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
  friend Test::AppCfgManagerMock;

  static constexpr char const *kCfgFilename = ".communal_calculator";

  virtual void SaveFile(Wrappers::STDOfStreamWrapper &of_stream,
                        const char *data, size_t size);

  std::filesystem::path dirPath_;
};

}  // namespace CommunalCalculator::Core

#endif  // SOURCEFILES_MODEL_CORE_APP_CFG_MANAGER_H_
