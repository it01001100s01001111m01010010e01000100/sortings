cmake_minimum_required(VERSION 3.16)

project(SortingTask)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(demo demo.cpp)
add_executable(unit_tests tests.cpp)