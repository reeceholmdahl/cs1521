#
cmake_minimum_required(VERSION 3.10)

project("Lab 6"
  VERSION 0.0.0
  DESCRIPTION "Lab 6 stacks/queues palindrome"
  LANGUAGES CXX)

add_compile_options(-Wall -Wextra -Wpedantic)

set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS OFF)

add_executable(lab6
  main.cpp
  isPalindrome.cpp
  PrecondViolatedExcep.cpp)
