# My ID: 5727889
cmake_minimum_required(VERSION 3.10)

project("Lab 5: Sort"
  VERSION 0.0.0
  DESCRIPTION "Learning to build an algorithm to sort a list interface."
  LANGUAGES CXX)

add_compile_options(-Wall -Wextra -Wpedantic)

set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS OFF)

add_executable(lab5
  main.cpp
  PrecondViolatedExcep.cpp)
