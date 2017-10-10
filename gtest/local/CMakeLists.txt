cmake_minimum_required(VERSION 3.8)

project(gtest_local)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)

include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(gtest_local gtest_local.cpp simple_test.cpp mock_turtle.h turtle.h)
target_link_libraries(gtest_local gtest_main gmock_main)