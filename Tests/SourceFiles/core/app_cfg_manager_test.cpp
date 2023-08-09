#include "core/app_cfg_manager_test.h"

#include <stdexcept>

namespace CommunalCalculator::Core::Test {

TEST_F(AppCfgManagerTest, SaveFilePassingArgs) {
  const std::filesystem::path kDirPath = "dir_path";
  const std::filesystem::path kFilename = ".communal_calculator";
  constexpr auto kFileFlags = std::fstream::out | std::ofstream::trunc;

  constexpr char const *kData = "123456789";
  constexpr int kDataSize = 9;

  auto file_path = kDirPath;
  file_path /= kFilename;

  EXPECT_CALL(stdOfStreamWrapperMock_, Open(file_path, kFileFlags));

  EXPECT_CALL(stdOfStreamWrapperMock_, IsOpen)
      .WillOnce(::testing::Return(true));

  EXPECT_CALL(stdOfStreamWrapperMock_,
              Write(::testing::StrEq(kData), kDataSize))
      .WillOnce(::testing::ReturnRef(stdOfStreamWrapperMock_));

  EXPECT_CALL(stdOfStreamWrapperMock_, Close);

  EXPECT_CALL(*appCfgManagerMock_, GetDirPath)
      .WillOnce(::testing::ReturnRef(kDirPath));

  appCfgManagerMock_->RealSaveFile(stdOfStreamWrapperMock_, kData, kDataSize);
}

TEST_F(AppCfgManagerTest, SaveFileIsOpenFalse) {
  const std::filesystem::path kDirPath = "dir_path";

  EXPECT_CALL(stdOfStreamWrapperMock_, Open);
  EXPECT_CALL(stdOfStreamWrapperMock_, IsOpen)
      .WillOnce(::testing::Return(false));

  EXPECT_CALL(*appCfgManagerMock_, GetDirPath)
      .WillOnce(::testing::ReturnRef(kDirPath));

  EXPECT_THROW(
      appCfgManagerMock_->RealSaveFile(stdOfStreamWrapperMock_, nullptr, 0),
      std::runtime_error);
}

}  // namespace CommunalCalculator::Core::Test
