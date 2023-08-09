#ifndef TESTS_SOURCEFILES_CORE_APP_CFG_MANAGER_TEST_H_
#define TESTS_SOURCEFILES_CORE_APP_CFG_MANAGER_TEST_H_

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "core/app_cfg_manager.h"

namespace CommunalCalculator::Core::Test {

class AppCfgManagerTest : public ::testing::Test {};

class AppCfgManagerMock : public Core::AppCfgManager {};

}  // namespace CommunalCalculator::Core::Test

#endif  // TESTS_SOURCEFILES_CORE_APP_CFG_MANAGER_TEST_H_
