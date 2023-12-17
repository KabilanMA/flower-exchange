#include <iostream>
#include "Exchange.h"

int main(int argc, char *argv[])
{
    // Check if the correct number of command-line arguments is provided
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " <orderCsvPath> <executeRepCsvPath>\n";
        return 1; // Exit with an error code
    }

    // Extract file paths from command-line arguments
    std::string orderCsvPath = argv[1];
    std::string executeRepCsvPath = argv[2];

    // Create an instance of the Exchange class
    Exchange exchange;

    // Read orders from order.csv
    exchange.readOrders(orderCsvPath);

    // Generate execute_rep.csv
    exchange.generateReport(executeRepCsvPath);

    return 0;
}