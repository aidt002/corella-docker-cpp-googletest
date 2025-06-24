cmake_minimum_required(VERSION 3.16)
project(c_unit_tests_base VERSION 1.0.0 LANGUAGES C)

# Require C11
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Default build type if none specified (for single-configuration generators)
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
endif()

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
  -Wold-style-definition
  -Wpointer-arith
  -Werror 
)

# Configure main library
file(GLOB_RECURSE APP_SOURCES
  ${CMAKE_SOURCE_DIR}/src/main/c/*.c
)
# Exclude the application entry point
list(FILTER APP_SOURCES EXCLUDE REGEX ".*/main\\.c$")

add_library(c_lib STATIC ${APP_SOURCES})
target_compile_features(c_lib PUBLIC c_std_11)
target_include_directories(c_lib
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/src/main/c>
    $<INSTALL_INTERFACE:include>
)

# Treat warnings as errors on supported compilers
if(MSVC)
  target_compile_options(c_lib PRIVATE /WX /W4)
else()
  target_compile_options(c_lib PRIVATE -Werror)
endif()

# Application executable
add_executable(c_app
  ${CMAKE_SOURCE_DIR}/src/main/c/main.c
)
target_link_libraries(c_app PRIVATE c_lib)

# Unit tests
enable_testing()

# Unity framework
add_library(Unity STATIC
${CMAKE_SOURCE_DIR}/src/test/c/unity/unity.c
)
target_include_directories(Unity PUBLIC
${CMAKE_SOURCE_DIR}/src/test/c/unity
)

# Discover test files (exclude unity.c)
file(GLOB_RECURSE TEST_SOURCES
${CMAKE_SOURCE_DIR}/src/test/c/*.c
)
list(FILTER TEST_SOURCES EXCLUDE REGEX ".*/unity\\.c$")

add_executable(c_tests ${TEST_SOURCES})
target_link_libraries(c_tests PRIVATE c_lib Unity)
target_include_directories(c_tests PRIVATE
${CMAKE_SOURCE_DIR}/src/main/c
${CMAKE_SOURCE_DIR}/src/test/c/unity
)

add_test(NAME c_unit_tests COMMAND c_tests)
