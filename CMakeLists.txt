cmake_minimum_required(VERSION 3.15)
project(TypicalProject)

include(cmake/compiler_flags.cmake)

set(LIBRARY_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/library")
set(SAMPLE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/sample")

set(LIBRARY_NAME "somelibrary")
set(SAMPLE_NAME "sample")

add_subdirectory(${LIBRARY_DIRECTORY})
add_subdirectory(${SAMPLE_DIRECTORY})
