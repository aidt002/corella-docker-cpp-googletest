cmake_minimum_required(VERSION 3.16)
project(basic_cpp_cmake_project VERSION 1.0 LANGUAGES CXX)

# C++ settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Common compiler warnings
add_compile_options(
  -Wall
  -Wextra
  -Wpedantic
  -Wshadow
  -Wconversion
  -Wsign-conversion
  -Wnull-dereference
  -Wduplicated-cond
  -Wduplicated-branches
  -Wlogical-op
  -Winit-self
  -Wuninitialized
  -Wpointer-arith
  -Werror 
)

# Enable warnings-as-errors by default
if(MSVC)
  add_compile_options(/W4 /WX)
else()
  add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

# Auto-discover library sources
file(GLOB_RECURSE LIB_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_library(cpp_app ${LIB_SOURCES})
target_include_directories(cpp_app PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

# Main executable
add_executable(basic_app src/main.cpp)
target_link_libraries(basic_app PRIVATE cpp_app)

# ----------------------------------------------------------------------------
# GoogleTest integration and test executable
# ----------------------------------------------------------------------------
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/releases/download/v1.17.0/googletest-1.17.0.tar.gz
)
FetchContent_MakeAvailable(googletest)

# Auto-discover test sources
file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp")
add_executable(cpp_unit_tests ${TEST_SOURCES})
target_link_libraries(cpp_unit_tests PRIVATE cpp_app gtest_main)

# Enable testing
enable_testing()

# Register tests
include(GoogleTest)
gtest_discover_tests(cpp_unit_tests)