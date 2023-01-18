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

set(
  CORE_SOURCES
  SourceFiles/core/communal_calculator.h
  SourceFiles/core/communal_calculator.cpp
)

set(
  UI_SOURCES
  SourceFiles/ui/main_window.h
  SourceFiles/ui/main_window.cpp
  SourceFiles/ui/mainwindow.ui
)

add_executable(${PROJECT_NAME}
  SourceFiles/main.cpp
  ${CORE_SOURCES}
  ${UI_SOURCES}
)

target_include_directories(${PROJECT_NAME} PRIVATE SourceFiles)

target_link_libraries(
  ${PROJECT_NAME}
  Qt6::Widgets
)
