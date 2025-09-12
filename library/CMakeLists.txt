project(${LIBRARY_NAME})

set(INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/include/sample_header.hpp")
set(SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/sample_source.cpp")

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
