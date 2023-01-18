cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 17)

project(communal-calculator)

# Qt setup ---

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(NOT DEFINED ENV{QT6_DIR})
  message(FATAL_ERROR "QT6_DIR was not found")
endif()

message(STATUS "Using Qt6: \"$ENV{QT6_DIR}\"")

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH}$ENV{QT6_DIR})

find_package(Qt6 REQUIRED COMPONENTS Widgets)

# ------------

add_executable(${PROJECT_NAME}
  SourceFiles/main.cpp
  SourceFiles/communal_calculator.h
  SourceFiles/communal_calculator.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE SourceFiles)

target_link_libraries(
  ${PROJECT_NAME}
  Qt6::Widgets
)
