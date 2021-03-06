﻿# CMake version
cmake_minimum_required(VERSION 3.8.2 FATAL_ERROR)

# Declare Project
project(AlphaMoku)

# Set output directories
set(DEFAULT_CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

# External libraries
set(BUILD_GTEST ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(Libraries/googletest)

# Include directories
include_directories(Includes)

# Compile options
include(CMake/CompileOptions.cmake)

# Add project modules
add_subdirectory(Sources/AlphaMoku)
add_subdirectory(UnitTest)

# Code coverage
option(BUILD_COVERAGE "Build code coverage" OFF)
if(CMAKE_BUILD_TYPE MATCHES Debug AND CMAKE_COMPILER_IS_GNUCXX AND BUILD_COVERAGE)
    include(CMake/CodeCoverage.cmake)
    setup_target_for_coverage(${PROJECT_NAME}_coverage UnitTest coverage)
endif()
