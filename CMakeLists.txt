project(libdde-auth)

cmake_minimum_required(VERSION 3.7)

set(VERSION 4.0)

#set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_FLAGS "-g -Wall")

add_subdirectory("interface")
add_subdirectory("src")
