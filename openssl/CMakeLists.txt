cmake_minimum_required(VERSION 3.8)
project(openssl)

find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})
set(openssl ${OPENSSL_LIBRARIES})

set(SOURCE_FILES openssl_example.cpp)
add_executable(openssl_example ${SOURCE_FILES})
target_link_libraries(openssl_example ${openssl})