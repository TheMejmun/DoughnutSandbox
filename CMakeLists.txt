cmake_minimum_required(VERSION 3.27)
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/external/vcpkg/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")
project(DoughnutSandbox)

set(CMAKE_CXX_STANDARD 20)

add_executable(DoughnutSandbox main.cpp)

add_subdirectory(external/Doughnut)
target_link_libraries(DoughnutSandbox Doughnut)
