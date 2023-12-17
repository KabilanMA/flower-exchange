#pragma once

#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

#include "Order.h"
#include "TransactionRecorder.h"

class OrderBook
{
public:
    // Constructor
    OrderBook(Order::InstrumentType name);

    void processOrder(Order &order, TransactionRecorder &transactionRecorder);

    void insertBuyOrder(Order &newOrder);

    void insertSellOrder(Order &newOrder);

private:
    //
    Order::InstrumentType name;

    // Member variables
    std::vector<Order> buyOrders;
    std::vector<Order> sellOrders;
};
