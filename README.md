# C++ Unit Tests Base Template

A dockerized C++ template for running unit tests with CMake and GoogleTest testing framework.

**⚠️ Important Note**: This repository contains a simple Calculator application for demonstration purposes only. You should replace the example code with your own C++ application while maintaining the same project structure and testing framework setup.

## Project Structure

```
├── CMakeLists.txt                   # Project configuration
├── include/                         # Public headers
│   └── Calculator.h                 # Example class declaration
├── src/                             # Source files
│   ├── main.cpp                     # Entry point
│   └── Calculator.cpp               # Example class implementation
├── tests/                           # Unit tests
|   ├── test_main.cpp                # Test runner
|   └── test_calculator.cpp          # Tests for Calculator
├── Dockerfile                       # Docker configuration
├── build_docker.sh                  # Docker build script
├── run_tests.sh                     # Test execution script
└── README.md                        # This file
```

## Features

- **C++ 17** with CMake build system
- **GoogleTest** testing framework for unit testing
- **Docker** support for containerized testing

### Docker Usage

1. **Build the Docker image**:
   ```bash
   ./build_docker.sh [image-name] [platform]
   ```
   
   Examples:
   ```bash
   ./build_docker.sh                           # Uses default: cpp-unit-tests-base
   ./build_docker.sh my-cpp-app                # Custom image name
   ```

2. **Run tests in Docker**:
   ```bash
   ./build_docker.sh my-cpp-app
   docker run --rm -it my-cpp-app ./run_tests.sh
   ```

3. **Interactive Docker session**:
   ```bash
   docker run -it --rm cpp-unit-tests-base bash
   # or you can mount your local folder in docker
   docker run -it --rm -v $(pwd):/app cpp-unit-tests-base bash

   ```

   Inside the container, you can run:

   ```bash
   ./run_tests.sh  # run the build and tests
   valgrind --leak-check=full ./build/basic_app # check for memory leaks
   ./build/cpp_unit_tests # run the test binary for more output
   ```


## Template Overview

**This is a Template - Replace with Your Code!**

This template provides the essential structure and configuration files for a C++ project with unit testing. **You should replace the example code with your own C++ application** while maintaining the project structure.

### Required Template Structure

Keep these key files and structure for your project:
- **`include/`** - Your header files  
- **`src/`** - Your main application code
- **`tests/`** - Your unit tests 
- **`CMakeLists.txt`** - CMake configuration (update for your project details)
- **`Dockerfile`** - Docker configuration for containerized testing. LEAVE AS IS.
- **`build_docker.sh`** - Docker build script. LEAVE AS IS
- **`run_tests.sh`** - Test execution script. LEAVE AS IS.

