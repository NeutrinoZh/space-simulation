cmake_minimum_required(VERSION 3.22)

project(space-simulation)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

message("Building with CMake version: ${CMAKE_VERSION}")

add_subdirectory(./wind/)

# executable

set(HEADERS
    ./include/space-simulation/simulation.h
    ./include/space-simulation/register.h
    ./include/space-simulation/camera.h
    ./include/space-simulation/mesh.h
    ./include/space-simulation/renderer.h
    ./include/space-simulation/default-res.h
    ./include/space-simulation/shader.h
) 

set(SOURCES
    ./src/simulation.cpp
    ./src/register.cpp
    ./src/camera.cpp
    ./src/default-res.cpp
    ./src/renderer.cpp
    ./src/shader.cpp
    ./src/main.cpp
) 

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ./include/)

# dependencies

## internal 
target_include_directories(${PROJECT_NAME} PUBLIC ./src/utils/include/)
target_link_libraries(${PROJECT_NAME} PUBLIC wind-utils)

target_include_directories(${PROJECT_NAME} PUBLIC ./src/window/include/)
target_link_libraries(${PROJECT_NAME} PUBLIC wind-window)

## external
find_package(glad CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glad::glad)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

find_package(spdlog REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)