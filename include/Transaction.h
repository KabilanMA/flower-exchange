#pragma once

#include <string>
#include <iostream>
#include "Order.h"

class Transaction
{
public:
    // Constructor
    Transaction(std::string orderID, std::string clientOrderID, std::string instrument, std::string side, std::string status, std::string quantity, std::string price);
    Transaction(std::string orderID, std::string clientOrderID, Order::InstrumentType instrument, int side, std::string status, int quantity, double price);

    // Getters
    std::string getOrderID() const;
    std::string getClientOrderId() const;
    std::string getInstrument() const;
    std::string getSide() const;
    std::string getStatus() const;
    std::string getQuantity() const;
    std::string getPrice() const;

private:
    std::string doubleToMoneyString(double value) const;
    std::string orderID;
    std::string clientOrderID;
    std::string instrument;
    std::string side;
    std::string status;
    std::string quantity;
    std::string price;
};
