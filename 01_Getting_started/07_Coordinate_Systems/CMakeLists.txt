cmake_minimum_required(VERSION 3.20)
PROJECT(CoordinateSystems)
SET(CMAKE_CXX_STANDARD 11)

include_directories(../../include)
link_directories(../../lib)

set(Target CoordinateSystems)
add_executable(${Target} coordinate_systems.cpp glad.c Shader.h Shader.cpp)
target_link_libraries(${Target} glfw3)

file(GLOB SHADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.shader)
foreach (SHADER ${SHADER_FILES})
    file(COPY ${SHADER} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
endforeach ()

file(GLOB RES_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.jpg)
foreach (RES ${RES_FILES})
    file(COPY ${RES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
endforeach ()
