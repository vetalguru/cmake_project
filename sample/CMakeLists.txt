project(calcsample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    ${LIBRARY_NAME})

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    ${LIBRARY_DIRECTORY}
)
