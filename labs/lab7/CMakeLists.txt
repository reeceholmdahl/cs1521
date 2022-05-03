cmake_minimum_required(VERSION 3.10)

project("Lab 7"
  VERSION 7.0
  DESCRIPTION "CS 1521 Lab 7: Basic Encryption"
  LANGUAGES CXX)

add_compile_options(-Wall -Wextra -Wpedantic)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(lab7
  rot5_13.cpp
  main.cpp)

#########################
# Create a second executable target: 'tests'
add_executable(tests
  rot5_13.cpp)

# Find the 'testRot5_rot13' library in the directory that also holds
# the source files:
find_library(TEST_ROT5_13
  NAMES testRot5_rot13
  PATHS ${CMAKE_SOURCE_DIR})

# Collect all values returned by 'find_library' into a single
# variable:
set(TEST_ROT5_13_LIBS ${TEST_ROT5_13})

# Use the libraries found above to link the 'tests' target with:
target_link_libraries(tests
  ${TEST_ROT5_13_LIBS})
