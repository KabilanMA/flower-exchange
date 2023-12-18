#pragma once

#include "Order.h"

/**
 * @brief The Transaction class represents a financial transaction in a trading system.
 *        It encapsulates information such as order ID, client order ID, instrument type, side,
 *        transaction status, quantity, and price.
 */
class Transaction
{
public:
    // Constructors
    /**
     * @brief Constructs a new Transaction object with specified transaction attributes (string) for record purpose.
     *
     * @param orderID The order ID of the transaction.
     * @param clientOrderID The client's order ID associated with the transaction.
     * @param instrument The instrument type of the transaction.
     * @param side The side of the transaction (buy-1/sell-1).
     * @param status The status of the transaction.
     * @param quantity The quantity involved in the order transaction.
     * @param price The price of the order transaction.
     * @param validationMessage Validation Message to record for each transaction.
     */
    Transaction(std::string orderID, std::string clientOrderID, std::string instrument, std::string side, std::string status, std::string quantity, std::string price, const std::string validationMessage);

    /**
     * @brief Constructs a new Transaction object with specified transaction attributes for record purpose.
     *
     * @param orderID The order ID of the transaction.
     * @param clientOrderID The client's order ID associated with the transaction.
     * @param instrument The instrument type of the transaction.
     * @param side The side of the transaction (buy/sell).
     * @param status The status of the transaction.
     * @param quantity The quantity involved in the transaction.
     * @param price The price of the transaction.
     * @param validationMessage Validation Message to record for each transaction.
     */
    Transaction(std::string orderID, std::string clientOrderID, Order::InstrumentType instrument, int side, std::string status, int quantity, double price, const std::string validationMessage);

    // Getters
    /**
     * @brief Gets the order ID of the transaction.
     * @return The order ID.
     */
    std::string getOrderID() const;

    /**
     * @brief Gets the client's order ID associated with the transaction.
     * @return The client's order ID.
     */
    std::string getClientOrderId() const;

    /**
     * @brief Gets the instrument type of the transaction.
     * @return The instrument type.
     */
    std::string getInstrument() const;

    /**
     * @brief Gets the side of the transaction (buy-1/sell-2).
     * @return The side of the transaction.
     */
    std::string getSide() const;

    /**
     * @brief Gets the status of the transaction.
     * @return The status of the transaction.
     */
    std::string getStatus() const;

    /**
     * @brief Gets the quantity involved in the transaction.
     * @return The quantity.
     */
    std::string getQuantity() const;

    /**
     * @brief Gets the price of the transaction.
     * @return The price.
     */
    std::string getPrice() const;

    /**
     * @brief Gets the transaction completion message.
     * @return The reason of the transaction.
     */
    std::string getReason() const;

private:
    /**
     * @brief Converts a double value to a string formatted as a money string.
     *
     * @param value The double value to be converted.
     * @return The money-formatted string.
     */
    std::string doubleToMoneyString(double value) const;

    std::string orderID;       ///< The order ID of the transaction.
    std::string clientOrderID; ///< The client's order ID associated with the transaction.
    std::string instrument;    ///< The instrument type of the transaction.
    std::string side;          ///< The side of the transaction (buy/sell).
    std::string status;        ///< The status of the transaction.
    std::string quantity;      ///< The quantity involved in the transaction.
    std::string price;         ///< The price of the transaction.
    std::string reason;        ///< Reason to indicate the transaction process.
};
