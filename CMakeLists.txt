cmake_minimum_required(VERSION 3.22)

project(space-simulation)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

message("Building with CMake version: ${CMAKE_VERSION}")

# executable

set(HEADERS
    ./include/space-simulation/simulation.h
    ./include/space-simulation/renderer.h
) 

set(SOURCES
    ./src/simulation.cpp
    ./src/renderer.cpp
    ./src/main.cpp
) 

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ./include/)

# dependencies

find_package(glad CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glad::glad)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

find_package(spdlog REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)