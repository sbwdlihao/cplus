cmake_minimum_required(VERSION 3.8)

project(gtest)

# local和download只能选择一个，否则会出现相同的gtest库冲突
add_subdirectory(local)
#add_subdirectory(download)