cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(.)

project(Euchr)

add_executable(Euchr src/main.cpp)

add_executable(test test/main.cpp)