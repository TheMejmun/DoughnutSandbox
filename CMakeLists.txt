cmake_minimum_required(VERSION 3.27)
project(DoughnutSandbox)

set(CMAKE_CXX_STANDARD 20)

add_executable(DoughnutSandbox main.cpp)

add_subdirectory(external/Doughnut)
target_link_libraries(DoughnutSandbox Doughnut)
