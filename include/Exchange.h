#pragma once

#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

#include "Order.h"
#include "OrderBook.h"
#include "TransactionRecorder.h"

class Exchange
{
public:
    // Constructor
    Exchange();

    // Read orders from order.csv // DONE
    void readOrders(const std::string &filename);

    // Process orders and generate execute_rep.csv
    void generateReport(const std::string &outputFilename) const;

private:
    // Helper method to process a single order
    void processOrder(Order &order);
    std::string validateInput(const std::vector<std::string> &row) const;

    // Orderbooks
    OrderBook rose;
    OrderBook lavender;
    OrderBook lotus;
    OrderBook tulip;
    OrderBook orchid;

    // logger
    TransactionRecorder transactionRecorder;

    // Orderbook for buy and sell orders
    std::vector<Order> buyOrderbook;
    std::vector<Order> sellOrderbook;
};
