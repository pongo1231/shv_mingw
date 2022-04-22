cmake_minimum_required(VERSION 3.12)

project(shv)

add_library(shv STATIC exports.cpp)
target_compile_features(shv PRIVATE cxx_std_11)
if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    add_definitions(-DUNICODE -D_UNICODE)
else()
    add_definitions(-municode)
endif()
target_compile_options(shv PRIVATE ${COMPILE_OPTIONS})

add_subdirectory(shv_test)
