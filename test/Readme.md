# Running Tests with CMake and Google Test

This guide provides instructions on how to run tests using CMake and Google Test in a C++ project.

## Prerequisites

- CMake installed on your system
- Google Test installed using vcpkg or another package manager
- Have the exchange_application executable file by running the application

## Setup

As you already have the repository, you can simply follow the steps to run the End2End test.

## Steps

1. First make sure to chang the path of `gtest` package path in the `test/CMakeLists.txt` Line#5.
2. Run CMake to generate the makefiles of test directory:
```
mkdir build
cd build
cmake ..
make 
```
3. Ensure the exchange_application is exists at `/build`

4. Run the executable EndToEnd file.
```
./ExchangeEndToEndTest
```

## Validation
By following the steps you can see the output .csv file in the Test_Samples folder. and you can see the results of e2e in the console.
