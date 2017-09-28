cmake_minimum_required(VERSION 3.8)
project(sub0)

set(SOURCE_FILES sub0.cpp)
add_executable(sub0 ${SOURCE_FILES})
target_link_libraries(sub0 ${glog})