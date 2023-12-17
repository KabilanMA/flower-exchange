#pragma once

#include <fstream>
#include <iostream>
#include <sstream>

#include "Order.h"
#include "OrderBook.h"
#include "TransactionRecorder.h"

/**
 * @brief The Exchange class represents a Flower exchange trading system.
 *        It generates the execution report for the given order file.
 */
class Exchange
{
public:
    /**
     * @brief Construct a new Exchange object.
     */
    Exchange();

    /**
     * @brief Reads orders from a CSV file and initializes the order books.
     *
     * @param filename The name of the CSV file containing orders.
     */
    void readOrders(const std::string &filename);

    /**
     * @brief Processes orders and generates an execution report in a CSV file.
     *
     * @param outputFilename The name of the output CSV file.
     */
    void generateReport(const std::string &outputFilename) const;

private:
    /**
     * @brief Processes a single order and updates the order books accordingly.
     *
     * @param order The order to be processed.
     */
    void processOrder(Order &order);

    /**
     * @brief Validates input data in a row from a CSV file.
     *
     * @param row The vector representing a row of data from the CSV file.
     * @return A string indicating the validation result.
     */
    std::string validateInput(const std::vector<std::string> &row) const;

    // Orderbooks
    OrderBook rose;     ///< Order book for rose flowers.
    OrderBook lavender; ///< Order book for lavender flowers.
    OrderBook lotus;    ///< Order book for lotus flowers.
    OrderBook tulip;    ///< Order book for tulip flowers.
    OrderBook orchid;   ///< Order book for orchid flowers.

    // Logger
    TransactionRecorder transactionRecorder; ///< Logger for recording transactions.

    // Orderbook for buy and sell orders
    std::vector<Order> buyOrderbook;  ///< Vector representing the buy order book.
    std::vector<Order> sellOrderbook; ///< Vector representing the sell order book.
};
