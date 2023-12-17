# Flower Exchange Program

## Build Instruction

### Prerequisites

Make sure you have the following installed on your system:

- CMake
- C++11 compiler
- Make (if not already included with your system)

### Build Steps

1. Clone the repository to your local machine:

   ```bash
   git clone https://github.com/KabilanMA/flower-exchange.git
   cd flower-exchange
   ```

2. Create a build directory:

   ```bash
   mkdir build
   cd build
   ```

3. Run CMake to generate the makefiles:

   ```bash
   cmake ..
   ```

4. Build the project using make:

   ```bash
   make
   ```

This will compile the project, and you should find the executable named `exchange_application` in the build directory.

## Usage

Before running the application, ensure you have the necessary CSV file:

- `order.csv` containing order data (Place it inside the data directory)

To run the application:

```bash
./exchange_application ../data/order.csv ../data/execute_rep.csv
```

## I/O

Both the input and output for the system are CSV files. order.csv (input) and execute_rep.csv(output, will be generated) file format are given below

### Input Format (CSV File)

| ClientOrderID | Instrument | Side | Quantity | Price |
| ------------- | ---------- | ---- | -------- | ----- |
| aa13          | Rose       | 1    | 100      | 55.00 |
| aa14          | Rose       | 1    | 100      | 65.00 |
| aa15          | Rose       | 2    | 300      | 1.00  |
| aa16          | Rose       | 1    | 100      | 2.00  |

### Output Format (CSV File)

| Order ID | Client Order ID | Instrument | Side | Exec Status | Quantity | Price |
| -------- | --------------- | ---------- | ---- | ----------- | -------- | ----- |
| ord1     | aa13            | Rose       | 1    | New         | 100      | 55.00 |
| ord2     | aa14            | Rose       | 1    | New         | 100      | 65.00 |
| ord3     | aa15            | Rose       | 2    | PFill       | 100      | 65.00 |
| ord2     | aa14            | Rose       | 1    | Fill        | 100      | 65.00 |
| ord3     | aa15            | Rose       | 2    | PFill       | 100      | 55.00 |
| ord1     | aa13            | Rose       | 1    | Fill        | 100      | 55.00 |
| ord4     | aa16            | Rose       | 1    | Fill        | 100      | 1.00  |
| ord3     | aa15            | Rose       | 2    | Fill        | 100      | 1.00  |
