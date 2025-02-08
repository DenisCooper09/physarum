cmake_minimum_required(VERSION 3.10...3.31)

project(physarum VERSION 0.1 LANGUAGES CXX DESCRIPTION "OpenGL GPU-accelerated physarum simulation.")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

add_subdirectory(src bin)

include(libs/libs.cmake)
build_libraries()
