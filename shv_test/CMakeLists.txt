cmake_minimum_required(VERSION 3.12)

project(shv_test)

add_library(shv_test MODULE main.cpp)
target_compile_features(shv_test PRIVATE cxx_std_11)
target_compile_options(shv_test PRIVATE -municode)
target_link_libraries(shv_test PRIVATE shv)
target_link_options(shv_test PRIVATE -static)
set_target_properties(shv_test PROPERTIES SUFFIX ".asi")