cmake_minimum_required(VERSION 3.20)
PROJECT(Shaders)
SET(CMAKE_CXX_STANDARD 11)

include_directories(../../include)
link_directories(../../lib)

set(Target Shaders)
add_executable(${Target} shaders.cpp glad.c)
target_link_libraries(${Target} glfw3)
