cmake_minimum_required(VERSION 3.5)

project(exercise_1_cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

# To separate executables
add_executable(taskA taskA.cpp)
add_executable(taskB taskB.cpp)
