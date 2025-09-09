cmake_minimum_required(VERSION 3.15)
project(TypicalProject)

include(cmake/compiler_flags.cmake)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/library")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/sample")
