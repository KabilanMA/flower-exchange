cmake_minimum_required(VERSION 3.12)
project(ExchangeEndToEndTest)

# Link against gtest
find_package(GTest CONFIG REQUIRED)

# Add the test executable
add_executable(ExchangeEndToEndTest ExchangeTest.cpp)

# Link against GTest and the source files
target_link_libraries(ExchangeEndToEndTest PRIVATE GTest::gtest GTest::gtest_main)

# Include the directory with the source code and the root directory
target_include_directories(ExchangeEndToEndTest PRIVATE ${CMAKE_SOURCE_DIR}/../include ${CMAKE_SOURCE_DIR}/src)

# Add source files to the test executable
target_sources(ExchangeEndToEndTest PRIVATE
    ${CMAKE_SOURCE_DIR}/../src/Exchange.cpp
    ${CMAKE_SOURCE_DIR}/../src/Order.cpp
    ${CMAKE_SOURCE_DIR}/../src/OrderBook.cpp
    ${CMAKE_SOURCE_DIR}/../src/Transaction.cpp
    ${CMAKE_SOURCE_DIR}/../src/TransactionRecorder.cpp
    # Add other relevant source files
)


# Register the test
include(GoogleTest)
gtest_discover_tests(ExchangeEndToEndTest)
