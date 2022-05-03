# My ID#: 5727889
cmake_minimum_required(VERSION 3.10)

project("Lab 4 getPosition"
  VERSION 0.0.0
  DESCRIPTION "Lab 4 using LinkedList version"
  LANGUAGES CXX)

add_compile_options(-Wall -Wextra -Wpedantic)

set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS OFF)

add_executable(lab4
  driver.cpp
  PrecondViolatedExcep.cpp)
