include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

if(CLANG_FORMAT_FIX)
  find_program(CLANG_FORMAT_EXE NAMES clang-format)

  if(NOT CLANG_FORMAT_EXE)
      message(FATAL_ERROR "clang-format not found!")
  endif()

  file(GLOB_RECURSE ALL_SRC
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
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

add_executable(${LIBRARY_NAME}_tests samplelibrary_tests.cpp)
target_link_libraries(${LIBRARY_NAME}_tests
  PRIVATE
  gtest_main
  ${LIBRARY_NAME}
)

enable_testing()
include(GoogleTest)
gtest_discover_tests(${LIBRARY_NAME}_tests)
