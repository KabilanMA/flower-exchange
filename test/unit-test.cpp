// test_myprogram.cpp

#include <gtest/gtest.h>
#include <fstream>
#include <sstream>
#include "src/Order.cpp"

// Function to read input from a string
void setInputString(const std::string& input, std::istream& in) {
     // Use std::istringstream to read from the string
    std::istringstream iss(input);
    in.rdbuf(iss.rdbuf());
}

// Test case for the main function
TEST(MainFunctionTest, ProcessOrdersAndGenerateReport) {
    // Set up input data
    std::string input = "aa13,Rose,1,100,55.00\n"
                        "aa14,Rose,1,100,65.00\n"
                        "aa15,Rose,2,300,1.00\n"
                        "aa16,Rose,1,100,2.00\n";
    
    // Create a stringstream and set the input data
    std::istringstream iss(input);
    setInputString(input, std::cin);

    // Set up expected output
    std::string expectedOutput = "SomeExpectedOutput";  // Replace with the actual expected output
    
    // Redirect cout to capture the output
    std::stringstream capturedOutput;
    std::streambuf* coutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());

    // Call the main function
    main(3, new char*[3]{"program_name", "order.csv", "execute_rep.csv"});

    // Restore cout
    std::cout.rdbuf(coutBuffer);

    // Compare the actual output with the expected output
    EXPECT_EQ(capturedOutput.str(), expectedOutput);
}

// Additional test cases can be added for different scenarios

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
