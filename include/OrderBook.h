#pragma once

#include <algorithm>

#include "Order.h"
#include "TransactionRecorder.h"

/**
 * @brief The OrderBook class represents a book of buy and sell orders for a specific instrument type.
 *        It manages the processing, insertion, and retrieval of orders.
 */
class OrderBook
{
public:
    // Constructor
    /**
     * @brief Constructs a new OrderBook for a specific instrument type.
     *
     * @param name The instrument type for which the order book is created.
     */
    OrderBook(Order::InstrumentType name);

    /**
     * @brief Processes an order and updates the order book accordingly.
     *
     * @param order The order to be processed.
     * @param transactionRecorder The transaction recorder for logging transactions.
     */
    void processOrder(Order &order, TransactionRecorder &transactionRecorder);

    /**
     * @brief Inserts a buy order into the order book.
     *
     * @param newOrder The buy order to be inserted.
     */
    void insertBuyOrder(Order &newOrder);

    /**
     * @brief Inserts a sell order into the order book.
     *
     * @param newOrder The sell order to be inserted.
     */
    void insertSellOrder(Order &newOrder);

private:
    Order::InstrumentType name; ///< The instrument type associated with the order book.

    std::vector<Order> buyOrders;  ///< Vector representing buy orders in the order book.
    std::vector<Order> sellOrders; ///< Vector representing sell orders in the order book.
};
