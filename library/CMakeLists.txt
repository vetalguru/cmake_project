project(calclibrary)

add_library(
    ${PROJECT_NAME}
    SHARED
    src/sample_source.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    $<BUILD_INTERFACE:${LIBRARY_DIRECTORY}>
    $<INSTALL_INTERFACE:include>
)
