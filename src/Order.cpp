#include "Order.h"

// Initialize the static member variable
int Order::nextID = 1;

// Constructor with validation
Order::Order(const std::string &clientOrderId, Order::InstrumentType instrument, int side, double price, int quantity, bool validOrder)
    : orderID("ord" + std::to_string(nextID++)), clientOrderId(clientOrderId), instrument(instrument), side(side), price(price), quantity(quantity), validOrder(validOrder)
{
}

Order::Order() : validOrder(false)
{
    orderID = "ord" + std::to_string(nextID++);
}

// Getter methods
std::string Order::getClientOrderId() const
{
    return clientOrderId;
}

std::string Order::getOrderID() const
{
    return orderID;
}

Order::InstrumentType Order::getInstrument() const
{
    return instrument;
}

int Order::getSide() const
{
    return side;
}

double Order::getPrice() const
{
    return price;
}

int Order::getQuantity() const
{
    return quantity;
}

void Order::setQuantity(int newQuantity)
{
    quantity = newQuantity;
}

void Order::setPriority(int newPriority)
{
    priority = newPriority;
}

int Order::getPriority() const
{
    return priority;
}

// Static method to convert string to InstrumentType
Order::InstrumentType Order::stringToInstrumentType(const std::string &instrumentString)
{
    if (instrumentString == "Rose")
    {
        return InstrumentType::Rose;
    }
    else if (instrumentString == "Lavender")
    {
        return InstrumentType::Lavender;
    }
    else if (instrumentString == "Lotus")
    {
        return InstrumentType::Lotus;
    }
    else if (instrumentString == "Tulip")
    {
        return InstrumentType::Tulip;
    }
    else if (instrumentString == "Orchid")
    {
        return InstrumentType::Orchid;
    }
    else
    {
        // Handle invalid instrument string (you may throw an exception, return a default value, etc.)
        throw std::invalid_argument("Invalid Instrument");
    }
}

// Static method to convert InstrumentType to string
std::string Order::instrumentTypeToString(const Order::InstrumentType &instrumentType)
{
    switch (instrumentType)
    {
    case Order::InstrumentType::Rose:
        return "Rose";
    case Order::InstrumentType::Lavender:
        return "Lavender";
    case Order::InstrumentType::Lotus:
        return "Lotus";
    case Order::InstrumentType::Tulip:
        return "Tulip";
    case Order::InstrumentType::Orchid:
        return "Orchid";
    default:
        throw std::invalid_argument("Invalid Instrument");
    }
}