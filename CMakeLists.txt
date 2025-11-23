cmake_minimum_required(VERSION 3.28.3)
project(fileMonitor)

set(CMAKE_CXX_STANDARD  20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS    OFF)

set(CMAKE_C_STANDARD    17)
set(CMAKE_C_STANDARD_REQUIRED   YES)
set(CMAKE_C_EXTENSIONS  OFF)

add_executable(${PROJECT_NAME} src/main.c)

target_link_libraries(${PROJECT_NAME} rFileHandler)

add_subdirectory(include)