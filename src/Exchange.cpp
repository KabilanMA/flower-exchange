#include "Exchange.h"

// Constructor
Exchange::Exchange() : rose(OrderBook(Order::InstrumentType::Rose)), lavender(OrderBook(Order::InstrumentType::Lavender)), lotus(OrderBook(Order::InstrumentType::Lotus)), orchid(OrderBook(Order::InstrumentType::Orchid)), tulip(OrderBook(Order::InstrumentType::Tulip)), transactionRecorder(TransactionRecorder())
{
}

// Read orders from order.csv
void Exchange::readOrders(const std::string &filename)
{
    std::fstream fin;
    fin.open(filename, std::ios::in);

    if (!fin.is_open())
    {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    std::string clientOrderId, instrument, traderId;
    int side;
    int quantity;
    double price;

    std::vector<std::string> row;
    std::string line, word;

    // Read header line (assuming it exists) and discard it
    if (std::getline(fin, line))
    {
        // Header line read and skipped
    }

    while (std::getline(fin, line))
    {
        std::stringstream s(line);

        row.clear();

        while (std::getline(s, word, ','))
        {
            row.push_back(word);
        }

        if (row.size() >= 5)
        {
            std::string validationMessage;
            try
            {
                validationMessage = Exchange::validateInput(row);
                clientOrderId = row[0];
                instrument = row[1];
                side = std::stoi(row[2]);
                quantity = std::stoi(row[3]);
                price = std::stod(row[4]);

                if (validationMessage == "Success")
                {
                    Order order(clientOrderId, Order::stringToInstrumentType(instrument), side, price, quantity, true);
                    processOrder(order, validationMessage);
                }
                else
                {
                    throw std::invalid_argument("Invalid Order");
                }
            }
            catch (const std::invalid_argument &e)
            {
                Order order;
                transactionRecorder.recordTransaction(order.getOrderID(), row[0], row[1], row[2], "Reject", row[3], row[4], validationMessage);
            }
        }
        else
        {
            Order order;
            transactionRecorder.recordTransaction(order.getOrderID(), row[0], row[1], row[2], "Reject", row[3], row[4], "Invalid Input Format");
        }
    }

    fin.close();
}

// Helper method to process a single order
void Exchange::processOrder(Order &order, const std::string validationMessage)
{
    switch (order.getInstrument())
    {
    case Order::InstrumentType::Rose:
        rose.processOrder(order, transactionRecorder, validationMessage);
        break;
    case Order::InstrumentType::Lavender:
        lavender.processOrder(order, transactionRecorder, validationMessage);
        break;
    case Order::InstrumentType::Lotus:
        lotus.processOrder(order, transactionRecorder, validationMessage);
        break;
    case Order::InstrumentType::Orchid:
        orchid.processOrder(order, transactionRecorder, validationMessage);
        break;
    case Order::InstrumentType::Tulip:
        tulip.processOrder(order, transactionRecorder, validationMessage);
        break;
    default:
        break;
    }
}

void Exchange::generateReport(const std::string &outputFilename) const
{
    std::ofstream outputFile(outputFilename);

    if (!outputFile.is_open())
    {
        std::cerr << "Error: Unable to create output file " << outputFilename << std::endl;
        return;
    }

    outputFile << "Order ID,Client Order ID,Instrument,Side,Exec Status,Quantity,Price,Reason\n";

    // Write each object's attributes to CSV
    for (const auto &obj : transactionRecorder.getAllTransactions())
    {
        outputFile << obj.getOrderID() << "," << obj.getClientOrderId() << "," << obj.getInstrument() << "," << obj.getSide() << "," << obj.getStatus() << "," << obj.getQuantity() << "," << obj.getPrice() << "," << obj.getReason() << "\n";
    }

    outputFile.close();
    std::cout << "CSV file written successfully: " << outputFilename << std::endl;
}

std::string Exchange::validateInput(const std::vector<std::string> &row) const
{
    std::string reason = "Success";

    // validate Client Order ID
    if (row[0] == "")
    {
        reason = "Invalid Client Order ID";
        return reason;
    }

    // validate Instrument
    if (row[1] == "")
    {
        reason = "Invalid Instrument";
        return reason;
    }
    else
    {
        Order::InstrumentType instTemp;
        try
        {
            instTemp = Order::stringToInstrumentType(row[1]);
        }
        catch (const std::invalid_argument &e)
        {
            reason = "Invalid Instrument";
            return reason;
        }
    }

    // validate Side
    if (row[2] == "")
    {
        reason = "Invalid Side";
        return reason;
    }
    else
    {
        int side;
        try
        {
            side = std::stoi(row[2]);
            if (side != 1 and side != 2)
            {
                reason = "Invalid Side";
                return reason;
            }
        }
        catch (const std::invalid_argument &e)
        {
            reason = "Invalid Side";
            return reason;
        }
    }

    // validate Quantity
    if (row[3] == "")
    {
        reason = "Invalid Size";
        return reason;
    }
    else
    {
        int quantity;
        try
        {
            quantity = std::stoi(row[3]);
            if (quantity % 10 != 0)
            {
                reason = "Invalid Size";
                return reason;
            }
            if (quantity > 1000  || quantity <100)
            {
                reason = "Invalid Size";
                return reason;
            }
        }
        catch (const std::invalid_argument &e)
        {
            reason = "Invalid Size";
            return reason;
        }
    }

    // validate Price
    if (row[4] == "")
    {
        reason = "Invalid Price";
        return reason;
    }
    else
    {
        int price;
        try
        {
            price = std::stod(row[4]);
            if (price <= 0.0)
            {
                reason = "Invalid Price";
                return reason;
            }
        }
        catch (const std::invalid_argument &e)
        {
            reason = "Invalid Price";
            return reason;
        }
    }

    return reason;
}