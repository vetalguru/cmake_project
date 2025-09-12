cmake_minimum_required(VERSION 3.15)
project(TypicalProject)

option(BUILD_TESTS "Build unit tests" ON)

include(cmake/compiler_flags.cmake)

set(LIBRARY_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/library")
set(SAMPLE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/sample")
set(TESTS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/tests")

set(LIBRARY_NAME "somelibrary")
set(SAMPLE_NAME "sample")

add_subdirectory(${LIBRARY_DIRECTORY})
add_subdirectory(${SAMPLE_DIRECTORY})

if(BUILD_TESTS)
    add_subdirectory(${TESTS_DIRECTORY})
endif()
