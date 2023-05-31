cmake_minimum_required(VERSION 3.20)
PROJECT(CreatingAWindow)
SET(CMAKE_CXX_STANDARD 11)

include_directories(../../include)
link_directories(../../lib)

set(Target CreatingAWindow)
add_executable(${Target} creating_a_window.cpp glad.c)
target_link_libraries(${Target} glfw3)