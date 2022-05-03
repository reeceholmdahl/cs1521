# My ID: 5727889
cmake_minimum_required(VERSION 3.10)

project("Project 7"
  VERSION 0.0.0
  DESCRIPTION "Project 7: Recursive binary tree processing"
  LANGUAGES CXX)

add_compile_options(-Wall -Wextra -Wpedantic)

set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS OFF)

add_executable(project7
  main.cpp
  PrecondViolatedExcep.cpp
  NotFoundException.cpp)
