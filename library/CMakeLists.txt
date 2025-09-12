project(${LIBRARY_NAME})

set(INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/include/sample_header.hpp")
set(SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/sample_source.cpp")

if(CLANG_FORMAT_FIX)
find_program(CLANG_FORMAT_EXE NAMES clang-format)

if(NOT CLANG_FORMAT_EXE)
    message(FATAL_ERROR "clang-format not found!")
endif()

file(GLOB_RECURSE ALL_SRC
  ${SOURCES}
  ${INCLUDES}
)

add_custom_target(format
    COMMAND ${CMAKE_COMMAND} -E echo "Running clang-format..."
    COMMAND ${CLANG_FORMAT_EXE}
            $<$<BOOL:${CLANG_FORMAT_FIX}>:-i>
            -style=file
            ${ALL_SRC}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
endif()

add_library(
    ${PROJECT_NAME}
    SHARED
    ${INCLUDES}
    ${SOURCES}
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    $<BUILD_INTERFACE:${LIBRARY_DIRECTORY}>
    $<INSTALL_INTERFACE:include>
)
