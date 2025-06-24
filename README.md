# C Unit Tests Base Template

A dockerized C template for running unit tests with CMake and Unity testing framework.

**⚠️ Important Note**: This repository contains a mock Todo application for demonstration purposes only. You should replace the example code with your own C application while maintaining the same project structure and testing framework setup.

## Project Structure

```
├── src/
│   ├── main/c/
│   │   ├── example_math.c           # Example file to test
│   │   └── main.c                   # Main application entry point
│   └── test/c/
│       ├── unity/
│       │   ├── unity.h              # Unity testing framework header
│       │   └── unity.c              # Unity testing framework implementation
│       ├── test_example_math.c              # Unit tests for example file
│       └── test_main.c              # Test runner main
├── CMakeLists.txt                   # CMake project configuration
├── Dockerfile                       # Docker configuration
├── build_docker.sh                  # Docker build script
├── run_tests.sh                     # Test execution script
└── README.md                        # This file
```

## Features

- **C11** with CMake build system
- **Unity** testing framework for unit testing
- **Docker** support for containerized testing

### Docker Usage

1. **Build the Docker image**:
   ```bash
   ./build_docker.sh [image-name] [platform]
   ```
   
   Examples:
   ```bash
   ./build_docker.sh                           # Uses default: c-unit-tests-base
   ./build_docker.sh my-c-app                  # Custom image name
   ```

2. **Run tests in Docker**:
   ```bash
   ./build_docker.sh my-c-app
   docker run --rm my-c-app ./run_tests.sh
   ```

3. **Interactive Docker session**:
   ```bash
   docker run -it --rm c-unit-tests-base bash
   # or you can mount your local folder in docker
   docker run -it --rm -v $(pwd):/app c-unit-tests-base bash

   ```

   Inside the container, you can run:

   ```bash
   ./run_tests.sh  # run the build and tests
   valgrind --leak-check=full ./build/c_app # check for memory leaks
   ./build/c_tests # run the test binary for more output
   ```


## Template Overview

**This is a Template - Replace with Your Code!**

This template provides the essential structure and configuration files for a C project with unit testing. **You should replace the example code with your own C application** while maintaining the project structure.

### Required Template Structure

Keep these key files and structure for your project:
- **`src/main/c/`** - Your main application code (replace `src/main/c/` with your own structure)
- **`src/test/c/`** - Your unit tests and Unity framework
- **`CMakeLists.txt`** - CMake configuration (update for your project details)
- **`Dockerfile`** - Docker configuration for containerized testing. LEAVE AS IS.
- **`build_docker.sh`** - Docker build script. LEAVE AS IS
- **`run_tests.sh`** - Test execution script. LEAVE AS IS.

### Unity Testing Framework

This template includes a lightweight Unity testing framework with these assertions:
- `TEST_ASSERT_TRUE(condition)`
- `TEST_ASSERT_FALSE(condition)`
- `TEST_ASSERT_EQUAL_INT(expected, actual)`
- `TEST_ASSERT_EQUAL_STRING(expected, actual)`
- `TEST_ASSERT_NULL(pointer)`
- `TEST_ASSERT_NOT_NULL(pointer)`

## Adapting This Template for Your Project

### Replacing the Example Code

1. **Update the main application**:
   - Replace the example main.c with your application's entry point
   - Update the CMakeLists.txt to reflect your executable name

2. **Replace the example tests**:
   - Replace files in `src/test/c/` with your own test files
   - Follow the same naming convention (test_filename.c)

3. **Update CMake configuration**:
   - Modify `CMakeLists.txt` to add any additional libraries your project needs

**Important**: Keep the Unity framework files and template build files but update their content as needed for your project.

### Adding New Features

1. **Create new header/source files** in your directory structure
2. **Add corresponding tests** in the test directory 
3. **Update CMakeLists.txt** if needed for additional dependencies

### CMake Dependencies

The template includes these key components:
- **Unity** testing framework (included)
- **C11** standard library features
- **Cross-platform** build support

Add new dependencies to `CMakeLists.txt`:
```cmake
# Find additional packages
find_package(YourLibrary REQUIRED)

# Link to your targets
target_link_libraries(your_target YourLibrary::YourLibrary)
```

## Troubleshooting

### Common Issues

1. **CMake version too old**: Update CMake to version 3.16 or higher

2. **Compiler errors**: Ensure you have a C11 compatible compiler (GCC 4.7+, Clang 3.3+)

3. **Memory leaks**: Use valgrind to detect memory issues:
   ```bash
   ```