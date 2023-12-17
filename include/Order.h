#pragma once

#include <string>
#include <stdexcept>

class Order
{
public:
    // Enum for allowed instrument values
    enum class InstrumentType
    {
        Rose,
        Lavender,
        Lotus,
        Tulip,
        Orchid
    };

    // Constructor
    Order(const std::string &clientOrderId, InstrumentType instrument, int side, double price, int quantity, bool validOrder);
    Order();

    // Getter methods
    std::string getClientOrderId() const;
    InstrumentType getInstrument() const;
    int getSide() const;
    double getPrice() const;
    int getQuantity() const;
    int getPriority() const;
    bool isCustomConstructor() const;
    std::string getOrderID() const;

    // setter
    void setQuantity(int newQuantity);
    void setPriority(int newPriority);

    // Static methods to convert string/InstrumentType to InstrumentType/string
    static InstrumentType stringToInstrumentType(const std::string &instrumentString);
    static std::string instrumentTypeToString(const InstrumentType &instrument);

private:
    // Member variables
    static int nextID;
    std::string orderID;
    std::string clientOrderId;
    InstrumentType instrument;
    int side;
    double price;
    int quantity;
    int priority;
    bool validOrder;
};
