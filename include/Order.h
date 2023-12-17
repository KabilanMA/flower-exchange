#pragma once

#include <stdexcept>
#include <string>

/**
 * @brief The Order class represents an order in a Flower exchange trading system.
 *        It encapsulates information such as order ID, client order ID, instrument type, side (buy/sell),
 *        price, quantity, and other attributes of a financial order.
 */
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

    // Constructors
    /**
     * @brief Constructs a new Order object with specified attributes.
     *
     * @param clientOrderId The client's order ID.
     * @param instrument The type of instrument (Rose, Lavender, Lotus, Tulip, Orchid).
     * @param side The side of the order (buy-1/sell-2).
     * @param price The price of the order.
     * @param quantity The quantity of the order.
     * @param validOrder Whether the order is valid or not.
     */
    Order(const std::string &clientOrderId, InstrumentType instrument, int side, double price, int quantity, bool validOrder);

    /**
     * @brief Constructs a default Order object with default values.
     */
    Order();

    // Getter methods
    /**
     * @brief Gets the client's order ID.
     * @return The client's order ID.
     */
    std::string getClientOrderId() const;

    /**
     * @brief Gets the instrument type of the order.
     * @return The instrument type.
     */
    InstrumentType getInstrument() const;

    /**
     * @brief Gets the side of the order (buy-1/sell-2).
     * @return The side of the order.
     */
    int getSide() const;

    /**
     * @brief Gets the price of the order.
     * @return The price of the order.
     */
    double getPrice() const;

    /**
     * @brief Gets the quantity of the order.
     * @return The quantity of the order.
     */
    int getQuantity() const;

    /**
     * @brief Gets the priority of the order.
     * @return The priority of the order.
     */
    int getPriority() const;

    /**
     * @brief Gets the unique order ID.
     * @return The order ID.
     */
    std::string getOrderID() const;

    // Setter methods
    /**
     * @brief Sets the quantity of the order.
     * @param newQuantity The new quantity.
     */
    void setQuantity(int newQuantity);

    /**
     * @brief Sets the priority of the order.
     * @param newPriority The new priority.
     */
    void setPriority(int newPriority);

    /**
     * @brief Static method to convert a string to InstrumentType.
     * @param instrumentString The string representation of the instrument.
     * @return The corresponding InstrumentType.
     */
    static InstrumentType stringToInstrumentType(const std::string &instrumentString);

    /**
     * @brief Static method to convert InstrumentType to a string.
     * @param instrument The InstrumentType.
     * @return The string representation of the instrument.
     */
    static std::string instrumentTypeToString(const InstrumentType &instrument);

private:
    static int nextID;         ///< Static variable to track the next available ID.
    std::string orderID;       ///< The unique order ID.
    std::string clientOrderId; ///< The client's order ID.
    InstrumentType instrument; ///< The type of instrument.
    int side;                  ///< The side of the order (buy-1/sell-2).
    double price;              ///< The price of the order.
    int quantity;              ///< The quantity of the order.
    int priority;              ///< The priority of the order.
    bool validOrder;           ///< Flag indicating whether the order is valid or not.
};
