# My ID#: 5727889
cmake_minimum_required(VERSION 3.10)

project("Bag with Receipts Project 2"
  VERSION 0.0.0
  DESCRIPTION "CS 1521 Project 2"
  LANGUAGES CXX)

add_compile_options(-Wall -Wextra -Wpedantic)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(project2
  driver.cpp)

add_executable(error-test1
  error-test1.cpp)

add_executable(error-test2
  error-test2.cpp)

add_executable(error-test3
  error-test3.cpp)
