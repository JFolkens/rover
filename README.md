# Rover Control

This repository contains a C++ project for controlling a tiny car.

## Build and test
Build and test instructions assume you are working on Ubuntu 24.04

Before building, install GoogleTest if it is not already available on your system.

```bash
sudo apt-get update
sudo apt-get install libgtest-dev cmake
```

Then build and run tests:

```bash
cmake -S . -B build
cmake --build build -j2
ctest --test-dir build --output-on-failure
```
