cmake_minimum_required(VERSION 3.10)

project("CS1521 Lab 2"
  VERSION 0.0.0
  DESCRIPTION "Lab 2, practicing encapsulation and ADT usage from a client perspective"
  LANGUAGES CXX)

add_compile_options(-Wall -Wextra -Wpedantic)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(lab2
  driver.cpp
  polynomial.cpp)
