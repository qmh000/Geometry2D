cmake_minimum_required(VERSION 3.12)

project(Geometry2D)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(query ${SOURCES})