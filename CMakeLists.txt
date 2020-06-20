
project(ENSEMBLE_WIN_REG)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(
    ensemble-win-reg
    "${CMAKE_SOURCE_DIR}/inc/registry.hpp"
    "${CMAKE_SOURCE_DIR}/src/registry.cpp"
    "${CMAKE_SOURCE_DIR}/test/main.cpp"
)
