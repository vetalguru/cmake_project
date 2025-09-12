include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

add_executable(${LIBRARY_NAME}_tests samplelibrary_tests.cpp)
target_link_libraries(${LIBRARY_NAME}_tests
    PRIVATE
    gtest_main
    ${LIBRARY_NAME}
)

enable_testing()
include(GoogleTest)
gtest_discover_tests(${LIBRARY_NAME}_tests)
