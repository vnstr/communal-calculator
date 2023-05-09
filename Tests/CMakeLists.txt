cmake_minimum_required(VERSION 3.24)

if (NOT DEFINED CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

project(communal-calculator-tests)

# Dependency -------------------------------------------------------------------

find_package(GTest REQUIRED)

set(
  third_party_libs
  GTest::gtest_main
  GTest::gmock_main
)

# Sources ----------------------------------------------------------------------

set(
  sources
  SourceFiles/main.cpp
)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${sources})

# Target -----------------------------------------------------------------------

set(target ${PROJECT_NAME})

add_executable(
  ${target}
  ${sources}
)

target_include_directories(
  ${target}
  PRIVATE
  SourceFiles
)

target_link_libraries(
  ${target}
  PRIVATE
  ${third_party_libs}
)

