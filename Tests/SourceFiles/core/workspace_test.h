#ifndef TESTS_SOURCEFILES_CORE_WORKSPACE_TEST_H_
#define TESTS_SOURCEFILES_CORE_WORKSPACE_TEST_H_

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "core/workspace.h"

namespace CommunalCalculator::Core::Test {

class WorkspaceTest : public ::testing::Test {};

class WorkspaceMock : public Core::Workspace {};

}  // namespace CommunalCalculator::Core::Test

#endif  // TESTS_SOURCEFILES_CORE_WORKSPACE_TEST_H_
