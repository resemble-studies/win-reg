# License: MIT. See LICENSE in root directory.
# Date: 2020/06/27

cmake_minimum_required(VERSION 3.0.1)

project("ensemble-win-reg")

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories("${CMAKE_SOURCE_DIR}/inc")

add_executable(
    "ensemble-win-reg"
    "${CMAKE_SOURCE_DIR}/inc/ensemble/registry.hpp"
    "${CMAKE_SOURCE_DIR}/src/ensemble/registry.cpp"
    "${CMAKE_SOURCE_DIR}/test/main.cpp"
)
