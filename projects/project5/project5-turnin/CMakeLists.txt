# My ID: 5727889
cmake_minimum_required(VERSION 3.10)

project("Project 5 Disc Storage Program"
  VERSION 0.0.0
  DESCRIPTION "Smart pointer use case in a text based program, CS 1521 Week 11 Project 5"
  LANGUAGES CXX)

add_compile_options(-Wall -Wextra -Wpedantic)

set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS OFF)

add_executable(project5
  main.cpp
  PrecondViolatedExcep.cpp
  Track.cpp
  Disc.cpp
  DiscList.cpp)
