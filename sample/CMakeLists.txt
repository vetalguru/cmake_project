project(${SAMPLE_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(INCLUDES)
set(SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")

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

add_executable(${PROJECT_NAME} ${SOURCES} ${INCLUDES})

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    ${LIBRARY_NAME})

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    ${LIBRARY_DIRECTORY}
)
