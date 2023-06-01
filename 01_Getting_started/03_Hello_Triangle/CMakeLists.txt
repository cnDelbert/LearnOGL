cmake_minimum_required(VERSION 3.20)
PROJECT(HelloTriangle)
SET(CMAKE_CXX_STANDARD 11)

include_directories(../../include)
link_directories(../../lib)

set(Target HelloTriangle)
add_executable(${Target} hello_triangle.cpp glad.c)
target_link_libraries(${Target} glfw3)