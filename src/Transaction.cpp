#include "Transaction.h"

#include <iostream>
#include <iomanip>
#include <sstream>

// Constructor definition
Transaction::Transaction(std::string orderID, std::string clientOrderID, std::string instrument, std::string side, std::string status, std::string quantity, std::string price, std::string validationMessage) : orderID(orderID), clientOrderID(clientOrderID), instrument(instrument), side(side), status(status), quantity(quantity), price(price), reason(validationMessage)
{
}

Transaction::Transaction(std::string orderID, std::string clientOrderID, Order::InstrumentType instrument, int side, std::string status, int quantity, double price, std::string validationMessage) : orderID(orderID), clientOrderID(clientOrderID), instrument(Order::instrumentTypeToString(instrument)), side(std::to_string(side)), status(status), quantity(std::to_string(quantity)), price(Transaction::doubleToMoneyString(price)), reason(validationMessage)
{
}

// Getter definitions
std::string Transaction::getOrderID() const
{
    return orderID;
}

std::string Transaction::getClientOrderId() const
{
    return clientOrderID;
}

std::string Transaction::getSide() const
{
    return side;
}

std::string Transaction::getStatus() const
{
    return status;
}

std::string Transaction::getQuantity() const
{
    return quantity;
}

std::string Transaction::getPrice() const
{
    return price;
}

std::string Transaction::getInstrument() const
{
    return instrument;
}

std::string Transaction::getReason() const
{
    return reason;
}

std::string Transaction::doubleToMoneyString(double value) const
{
    // Use std::ostringstream for string formatting
    std::ostringstream oss;

    // Set the precision for the decimal part
    oss << std::fixed << std::setprecision(2);

    // Format the double value as a money string
    oss << value;

    // Return the formatted string
    return oss.str();
}