#include <gtest/gtest.h>
#include "Exchange.h"
#include <fstream>

// Test fixture for end-to-end testing
class ExchangeEndToEndTest : public ::testing::Test
{
protected:
    // Set up common resources needed for the tests
    void SetUp() override
    {
        // You can initialize any objects or variables here before each test
    }

    // Clean up resources after the tests
    void TearDown() override
    {
        // You can clean up any resources or objects created during the tests
    }

    // Helper function to read the content of a file into a string
    std::string readFile(const std::string &filePath) const
    {
        std::ifstream file(filePath);
        if (file)
        {
            return std::string(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
        }
        else
        {
            return ""; // Return an empty string if the file cannot be opened
        }
    }

    // Declare any common variables used across tests
};

// End-to-end test for the full functionality of the system
TEST_F(ExchangeEndToEndTest, FullFunctionalityTest)
{
    // Arrange: Set up the initial state or conditions
    std::string orderCsvPath = "../Test_Samples/order.csv";
    std::string executeRepCsvPath = "../Test_Samples/output.csv";
    std::string expectedOutputPath = "../Test_Samples/expected_output.csv";
    std::string programPath = "../../build/exchange_application";

    // Act: Perform the action you want to test (call the main functionality of your program)
    std::string command = programPath + " " + orderCsvPath + " " + executeRepCsvPath;
    int result = system(command.c_str());

    // Assert: Check the expected results
    // For example, check the return code and compare the generated output with the expected output
    EXPECT_EQ(result, 0); // Assuming your program returns 0 on success

    std::string generatedOutput = readFile(executeRepCsvPath);
    std::string expectedOutput = readFile(expectedOutputPath);
    EXPECT_EQ(generatedOutput, expectedOutput);
}

// Add more end-to-end test cases as needed for testing different scenarios

// Entry point for running the tests
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
