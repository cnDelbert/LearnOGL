cmake_minimum_required(VERSION 3.20)
PROJECT(Colors)
SET(CMAKE_CXX_STANDARD 11)

include_directories(../../include)
link_directories(../../lib)

set(Target Colors)
add_executable(${Target} colors.cpp glad.c)
target_link_libraries(${Target} glfw3)

file(GLOB SHADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/shaders/*.*)
foreach (SHADER ${SHADER_FILES})
    file(COPY ${SHADER} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/shaders/)
endforeach ()

file(GLOB RES_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.jpg)
foreach (RES ${RES_FILES})
    file(COPY ${RES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
endforeach ()
