# tests/CMakeLists.txt

# Use FetchContent to bring in GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/v1.17.0.zip
)
# Prevent overriding the parent project's compiler options
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Auto-discover test sources
file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(calculator_tests ${TEST_SOURCES})

# Link test executable against calculator library and GTest
target_link_libraries(calculator_tests
  PRIVATE
    calculator
    gtest_main
)

# Inherit warning flags from parent scope; no need to re-specify

# Register tests
include(GoogleTest)
gtest_discover_tests(calculator_tests)