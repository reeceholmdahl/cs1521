# My ID#: 5727889
cmake_minimum_required(VERSION 3.10)

project("Lab 3 Sets"
  VERSION 0.0.0
  DESCRIPTION "Array-based implementation of ADT set"
  LANGUAGES CXX)

add_compile_options(-Wall -Wextra -Wpedantic)

set(CXX_STANDARD 14)
set(CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS OFF)

add_executable(lab3
  lab3.cpp)
