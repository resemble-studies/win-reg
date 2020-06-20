
project(ENSEMBLE_WIN_REG)

add_executable(
    ENSEMBLE_WIN_REG
    "${CMAKE_SOURCE_DIR}/inc/registry.hpp"
    "${CMAKE_SOURCE_DIR}/src/registry.cpp"
    "${CMAKE_SOURCE_DIR}/test/main.cpp"
)
