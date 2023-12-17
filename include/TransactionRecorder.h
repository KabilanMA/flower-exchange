#pragma once

#include <vector>

#include "Order.h"
#include "Transaction.h"

/**
 * @brief The TransactionRecorder class manages and records financial transactions in the exchange trading system.
 *        It keeps track of recorded transactions and provides a getter to retrieve all transactions.
 */
class TransactionRecorder
{
public:
    // Constructor
    /**
     * @brief Constructs a new TransactionRecorder object.
     */
    TransactionRecorder();

    /**
     * @brief Records a transaction with specified attributes.
     *
     * @param orderID The order ID of the transaction.
     * @param clientOrderID The client's order ID associated with the transaction.
     * @param instrument The instrument type of the transaction.
     * @param side The side of the transaction (buy-1/sell-2).
     * @param status The status of the transaction.
     * @param quantity The quantity involved in the transaction.
     * @param price The price of the transaction.
     */
    void recordTransaction(std::string orderID, std::string clientOrderID, Order::InstrumentType instrument, int side, std::string status, int quantity, double price);

    /**
     * @brief Records a transaction with specified attributes.
     *
     * @param orderID The order ID of the transaction.
     * @param clientOrderID The client's order ID associated with the transaction.
     * @param instrument The instrument type of the transaction.
     * @param side The side of the transaction (buy/sell).
     * @param status The status of the transaction.
     * @param quantity The quantity involved in the transaction.
     * @param price The price of the transaction.
     */
    void recordTransaction(std::string orderID, std::string clientOrderID, std::string instrument, std::string side, std::string status, std::string quantity, std::string price);

    /**
     * @brief Gets all recorded transactions.
     * @return A vector containing all recorded transactions.
     */
    std::vector<Transaction> getAllTransactions() const;

private:
    std::vector<Transaction> transactions; ///< Vector containing all recorded transactions.
};
