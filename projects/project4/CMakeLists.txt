# My ID: 5727889
cmake_minimum_required(VERSION 3.10)

project("Project 4"
  VERSION 0.0.0
  DESCRIPTION "CS 1521-9 Project 4 Infix Expressions with Stacks"
  LANGUAGES CXX)

add_compile_options(-Wall -Wextra -Wpedantic)

set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS OFF)

add_executable(project4
  driver.cpp
  Infix.cpp)
