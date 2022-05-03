# My ID: 5727889
cmake_minimum_required(VERSION 3.10)

project("Project6 Bank Simulation"
  VERSION 0.0.0
  DESCRIPTION "Project6, two execs: one teller, and three teller"
  LANGUAGES CXX)

add_compile_options(-Wall -Wextra -Wpedantic)

set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS OFF)

add_executable(oneTeller
  oneTeller/project6.cpp
  Event.cpp
  PrecondViolatedExcep.cpp
  oneTeller/EventBuilder.cpp
  oneTeller/Statistics.cpp
  oneTeller/Simulation.cpp)

add_executable(threeTeller
  threeTeller/project6.cpp
  Event.cpp
  PrecondViolatedExcep.cpp
  threeTeller/EventBuilder.cpp
  threeTeller/Statistics.cpp
  threeTeller/Simulation.cpp)
