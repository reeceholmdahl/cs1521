cmake_minimum_required(VERSION 3.1.0)

project("Tic Tac Toe"
  LANGUAGES CXX)

add_compile_options(-Wall -Wextra -Wpedantic)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(tictactoe
  main.cpp
  game.cpp
  board.cpp
  player.cpp)
