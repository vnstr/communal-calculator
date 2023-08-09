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

void AppCfgManager::SaveFile(Wrappers::STDOfStreamWrapper &of_stream,
                             const char *data, size_t size) {
  constexpr auto kFileFlags = std::fstream::out | std::ofstream::trunc;

  auto file_path = GetDirPath();
  file_path /= kCfgFilename;

  of_stream.Open(file_path, kFileFlags);
  if (!of_stream.IsOpen()) {
    throw std::runtime_error(
        "AppCfgManager::SaveFile: of_stream.IsOpen() has returned false");
  }

  of_stream.Write(data, static_cast<long>(size));
  of_stream.Close();
}

}  // namespace CommunalCalculator::Core
