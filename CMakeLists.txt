cmake_minimum_required(VERSION 3.8)
project(cplus)

set(CMAKE_CXX_STANDARD 11)

message("INCLUDE_DIRECTORIES = ${INCLUDE_DIRECTORIES}")
set(INCLUDE_DIRECTORIES include)
add_subdirectory(sub_module0)

set(SOURCE_FILES main.cpp)
add_executable(cplus ${SOURCE_FILES})