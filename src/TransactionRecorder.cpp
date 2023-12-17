// TransactionRecorder.cpp
#include "TransactionRecorder.h"

// Constructor definition
TransactionRecorder::TransactionRecorder() {}

// Member function to record a transaction
void TransactionRecorder::recordTransaction(std::string orderID, std::string clientOrderID, Order::InstrumentType instrument, int side, std::string status, int quantity, double price)
{
    Transaction transaction(orderID, clientOrderID, instrument, side, status, quantity, price);
    transactions.push_back(transaction);
}

void TransactionRecorder::recordTransaction(std::string orderID, std::string clientOrderID, std::string instrument, std::string side, std::string status, std::string quantity, std::string price)
{
    Transaction transaction(orderID, clientOrderID, instrument, side, status, quantity, price);
    transactions.push_back(transaction);
}

// getter
std::vector<Transaction> TransactionRecorder::getAllTransactions() const
{
    return transactions;
}