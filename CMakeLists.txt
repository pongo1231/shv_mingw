cmake_minimum_required(VERSION 3.12)

project(shv)

add_library(shv STATIC exports.cpp)
target_compile_features(shv PRIVATE cxx_std_11)
target_compile_options(shv PRIVATE -municode)

add_subdirectory(shv_test)