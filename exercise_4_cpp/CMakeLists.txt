cmake_minimum_required(VERSION 3.10)

project(exercise_4_cpp)

# Set C++ standard and additional flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

# Find the GTKMM package (version 3.0 or newer)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

# Add the executable for the main project
add_executable(exercise_4_cpp main.cpp)

# Link the GTKMM libraries to the main executable
target_link_libraries(exercise_4_cpp ${GTKMM_LIBRARIES})

# Include GTKMM headers in the main executable
target_include_directories(exercise_4_cpp PRIVATE ${GTKMM_INCLUDE_DIRS})

# Add the necessary GTKMM compile flags
target_compile_options(exercise_4_cpp PRIVATE ${GTKMM_CFLAGS_OTHER})

# Add the executable for oppg1 (optional, if it doesn't use GTKMM, you don't need to modify it)
add_executable(oppg1 oppg1.cpp)
