cmake_minimum_required(VERSION 3.20)
PROJECT(Shaders)
SET(CMAKE_CXX_STANDARD 11)

include_directories(../../include)
link_directories(../../lib)

set(Target Shaders)
add_executable(${Target} shaders.cpp glad.c Shader.h Shader.cpp)
target_link_libraries(${Target} glfw3)

file(GLOB SHADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.shader)
foreach (SHADER IN LISTS ${SHADER_FILES})
    file(COPY ${SHADER} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
endforeach ()
