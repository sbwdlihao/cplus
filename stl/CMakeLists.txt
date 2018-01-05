cmake_minimum_required(VERSION 3.8)
project(stl)

set(CMAKE_CXX_STANDARD 11)

#message("${CMAKE_CURRENT_SOURCE_DIR}")
#add_subdirectory(/Users/bencong/CLionProjects/cplus/gtest/local/lib/googletest-master /Users/bencong/CLionProjects/cplus/stl)
#
#include_directories(/Users/bencong/CLionProjects/cplus/gtest/local/lib/googletest-master/googletest/include)
#include_directories(/Users/bencong/CLionProjects/cplus/gtest/local/lib/googletest-master/googlemock/include)

add_executable(stl stl.cpp array_test.cpp map_test.cpp protocol.h file_test.cpp string_test.cpp)
target_link_libraries(stl gtest_main gmock_main)