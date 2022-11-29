cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 17)

project(communal-calculator)

add_executable(${PROJECT_NAME}
  SourceFiles/main.cpp
  SourceFiles/communal_calculator.h
  SourceFiles/communal_calculator.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE SourceFiles)

