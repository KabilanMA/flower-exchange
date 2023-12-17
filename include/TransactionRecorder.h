#pragma once

#include <vector>
#include "Order.h"
#include <iostream>
#include "Transaction.h"

class TransactionRecorder
{
public:
    // Constructor
    TransactionRecorder();

    // Member function to record a transaction
    void recordTransaction(std::string orderID, std::string clientOrderID, Order::InstrumentType instrument, int side, std::string status, int quantity, double price);
    void recordTransaction(std::string orderID, std::string clientOrderID, std::string instrument, std::string side, std::string status, std::string quantity, std::string price);

    // getter
    std::vector<Transaction> getAllTransactions() const;

private:
    std::vector<Transaction> transactions;
};
