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
};

// End-to-end test for the input - 1
TEST_F(ExchangeEndToEndTest, FullFunctionalityTest_1)
{
    // Arrange: Set up the initial state or conditions
    std::string orderCsvPath = "../Test_Samples/inputs/orders-1.csv";
    std::string executeRepCsvPath = "../Test_Samples/output/output-1.csv";
    std::string expectedOutputPath = "../Test_Samples/expected/1-execution_rep.csv";
    std::string programPath = "../../build/exchange_application";

    // Act: Perform the action you want to test (call the main functionality of your program)
    std::string command = programPath + " " + orderCsvPath + " " + executeRepCsvPath;
    int result = system(command.c_str());

    // Assert: Check the expected results
    // For example, check the return code and compare the generated output with the expected output
    // EXPECT_EQ(result, 0); // Assuming your program returns 0 on success

    std::string generatedOutput = readFile(executeRepCsvPath);
    std::string expectedOutput = readFile(expectedOutputPath);
    EXPECT_EQ(generatedOutput, expectedOutput);
}

// End-to-end test for the input 2
TEST_F(ExchangeEndToEndTest, FullFunctionalityTest_2)
{
    std::string orderCsvPath = "../Test_Samples/inputs/orders-2.csv";
    std::string executeRepCsvPath = "../Test_Samples/output/output-2.csv";
    std::string expectedOutputPath = "../Test_Samples/expected/2-execution_rep.csv";
    std::string programPath = "../../build/exchange_application";

    std::string command = programPath + " " + orderCsvPath + " " + executeRepCsvPath;
    int result = system(command.c_str());

    std::string generatedOutput = readFile(executeRepCsvPath);
    std::string expectedOutput = readFile(expectedOutputPath);
    EXPECT_EQ(generatedOutput, expectedOutput);
}

// End-to-end test for the input 3
TEST_F(ExchangeEndToEndTest, FullFunctionalityTest_3)
{
    std::string orderCsvPath = "../Test_Samples/inputs/orders-3.csv";
    std::string executeRepCsvPath = "../Test_Samples/output/output-3.csv";
    std::string expectedOutputPath = "../Test_Samples/expected/3-execution_rep.csv";
    std::string programPath = "../../build/exchange_application";

    std::string command = programPath + " " + orderCsvPath + " " + executeRepCsvPath;
    int result = system(command.c_str());

    std::string generatedOutput = readFile(executeRepCsvPath);
    std::string expectedOutput = readFile(expectedOutputPath);
    EXPECT_EQ(generatedOutput, expectedOutput);
}

// End-to-end test for the input 4
TEST_F(ExchangeEndToEndTest, FullFunctionalityTest_4)
{
    std::string orderCsvPath = "../Test_Samples/inputs/orders-4.csv";
    std::string executeRepCsvPath = "../Test_Samples/output/output-4.csv";
    std::string expectedOutputPath = "../Test_Samples/expected/4-execution_rep.csv";
    std::string programPath = "../../build/exchange_application";

    std::string command = programPath + " " + orderCsvPath + " " + executeRepCsvPath;
    int result = system(command.c_str());

    std::string generatedOutput = readFile(executeRepCsvPath);
    std::string expectedOutput = readFile(expectedOutputPath);
    EXPECT_EQ(generatedOutput, expectedOutput);
}


// End-to-end test for the input 5
TEST_F(ExchangeEndToEndTest, FullFunctionalityTest_5)
{
    std::string orderCsvPath = "../Test_Samples/inputs/orders-5.csv";
    std::string executeRepCsvPath = "../Test_Samples/output/output-5.csv";
    std::string expectedOutputPath = "../Test_Samples/expected/5-execution_rep.csv";
    std::string programPath = "../../build/exchange_application";

    std::string command = programPath + " " + orderCsvPath + " " + executeRepCsvPath;
    int result = system(command.c_str());

    std::string generatedOutput = readFile(executeRepCsvPath);
    std::string expectedOutput = readFile(expectedOutputPath);
    EXPECT_EQ(generatedOutput, expectedOutput);
}


// End-to-end test for the input 5
TEST_F(ExchangeEndToEndTest, FullFunctionalityTest_6)
{
    std::string orderCsvPath = "../Test_Samples/inputs/orders-5.csv";
    std::string executeRepCsvPath = "../Test_Samples/output/output-5.csv";
    std::string expectedOutputPath = "../Test_Samples/expected/5-execution_rep.csv";
    std::string programPath = "../../build/exchange_application";

    std::string command = programPath + " " + orderCsvPath + " " + executeRepCsvPath;
    int result = system(command.c_str());

    std::string generatedOutput = readFile(executeRepCsvPath);
    std::string expectedOutput = readFile(expectedOutputPath);
    EXPECT_EQ(generatedOutput, expectedOutput);
}


// End-to-end test for the input 7
TEST_F(ExchangeEndToEndTest, FullFunctionalityTest_7)
{
    std::string orderCsvPath = "../Test_Samples/inputs/orders-7.csv";
    std::string executeRepCsvPath = "../Test_Samples/output/output-7.csv";
    std::string expectedOutputPath = "../Test_Samples/expected/7-execution_rep.csv";
    std::string programPath = "../../build/exchange_application";

    std::string command = programPath + " " + orderCsvPath + " " + executeRepCsvPath;
    int result = system(command.c_str());

    std::string generatedOutput = readFile(executeRepCsvPath);
    std::string expectedOutput = readFile(expectedOutputPath);
    EXPECT_EQ(generatedOutput, expectedOutput);
}

// Entry point for running the tests
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
