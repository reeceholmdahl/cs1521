# My ID#: 5727889
cmake_minimum_required(VERSION 3.10)

project("Sequence Stats Project 1"
  VERSION 0.0.0
  DESCRIPTION "CS 1521 Project 1"
  LANGUAGES CXX)

add_compile_options(-Wall -Wextra -Wpedantic)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(project1
  tests.cpp
  sequence-stats.cpp)

