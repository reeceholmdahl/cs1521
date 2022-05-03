cmake_minimum_required(VERSION 3.10)

project("Project 3"
  VERSION 0.0.0
  DESCRIPTION "Project 3: Linked Set and Spell Checking"
  LANGUAGES CXX)

add_compile_options(-Wall -Wextra -Wpedantic)

set(CXX_STANDARD 14)
set(CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS OFF)

add_executable(main_test
  main.cpp)

add_executable(lab3_test
  lab3driver.cpp)
