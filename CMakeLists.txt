cmake_minimum_required(VERSION 3.8)
project(cplus)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)
find_package(Glog REQUIRED)
include_directories(${LIBGLOG_INCLUDE_DIR})
set(glog ${LIBGLOG_LIBRARY})

add_subdirectory(sub_module0)
add_subdirectory(gtest)
add_subdirectory(openssl)

set(SOURCE_FILES main.cpp)
add_executable(cplus ${SOURCE_FILES})
target_link_libraries(cplus ${glog})