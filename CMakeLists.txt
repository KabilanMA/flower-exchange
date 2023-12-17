# CMakeLists.txt

cmake_minimum_required(VERSION 3.12)
project(exchange_application)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable
add_executable(exchange_application
    src/main.cpp
    src/Exchange.cpp
    src/OrderBook.cpp
    src/Order.cpp
    src/Transaction.cpp
    src/TransactionRecorder.cpp
)

# Include directories
target_include_directories(exchange_application PRIVATE include)

# Specify the location of the order.csv and execute_rep.csv files as compile definitions
target_compile_definitions(exchange_application PRIVATE
    ORDER_CSV_PATH="${CMAKE_SOURCE_DIR}/data/order.csv"
    EXECUTE_REP_CSV_PATH="${CMAKE_SOURCE_DIR}/data/execute_rep.csv"
)
