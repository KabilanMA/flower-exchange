#include "OrderBook.h"

// Constructor
OrderBook::OrderBook(Order::InstrumentType name) : name(name)
{
}

// sell order in ascending order
// buy order in descending order

void OrderBook::processOrder(Order &order, TransactionRecorder &transactionRecorder, const std::string validationMessage)
{
    int baseQuantity = order.getQuantity();
    // insert according to sell order or buy order

    if (order.getSide() == 1) // Buy order
    {
        for (auto sellOrder = sellOrders.begin(); sellOrder != sellOrders.end();)
        {
            if (sellOrder->getPrice() <= order.getPrice()) // can be buy less than or equal to the requested amount
            {
                int price = sellOrder->getPrice();
                if (order.getQuantity() <= sellOrder->getQuantity()) // if the seller has more than the buyer requires
                {
                    // buyer gets all the requests
                    transactionRecorder.recordTransaction(order.getOrderID(), order.getClientOrderId(), name, order.getSide(), "Fill", baseQuantity, price, validationMessage);

                    if (order.getQuantity() == sellOrder->getQuantity()) // if the seller and buyer requires same amount
                    {
                        transactionRecorder.recordTransaction(sellOrder->getOrderID(), sellOrder->getClientOrderId(), name, sellOrder->getSide(), "Fill", sellOrder->getQuantity(), price, validationMessage);
                        sellOrder->setQuantity(0);
                        sellOrder = sellOrders.erase(sellOrder);
                    }
                    else // If the seller has more to sell than the buyer requested
                    {
                        transactionRecorder.recordTransaction(sellOrder->getOrderID(), sellOrder->getClientOrderId(), name, sellOrder->getSide(), "PFill", order.getQuantity(), price, validationMessage);
                        sellOrder->setQuantity(sellOrder->getQuantity() - order.getQuantity());
                        sellOrder++;
                    }
                    order.setQuantity(0);
                    break;
                }
                else // if the current seller has less than the buyer's required amount
                {
                    transactionRecorder.recordTransaction(order.getOrderID(), order.getClientOrderId(), name, order.getSide(), "PFill", sellOrder->getQuantity(), price, validationMessage);

                    transactionRecorder.recordTransaction(sellOrder->getOrderID(), sellOrder->getClientOrderId(), name, sellOrder->getSide(), "Fill", sellOrder->getQuantity(), price, validationMessage);

                    order.setQuantity(order.getQuantity() - sellOrder->getQuantity());
                    sellOrder->setQuantity(0);
                    sellOrder = sellOrders.erase(sellOrder);
                }
            }
            else
            {
                break;
            }
        }
        if (order.getQuantity() > 0)
        {
            if (order.getQuantity() == baseQuantity)
            {
                // status NEW
                transactionRecorder.recordTransaction(order.getOrderID(), order.getClientOrderId(), name, order.getSide(), "New", order.getQuantity(), order.getPrice(), validationMessage);
            }
            OrderBook::insertBuyOrder(order);
        }
    }
    else // sell order
    {
        for (auto buyOrder = buyOrders.begin(); buyOrder != buyOrders.end();)
        {
            if (buyOrder->getPrice() >= order.getPrice())
            {
                int price = buyOrder->getPrice();
                if (order.getQuantity() <= buyOrder->getQuantity())
                {
                    transactionRecorder.recordTransaction(order.getOrderID(), order.getClientOrderId(), name, order.getSide(), "Fill", baseQuantity, price, validationMessage);

                    if (order.getQuantity() == buyOrder->getQuantity())
                    {
                        transactionRecorder.recordTransaction(buyOrder->getOrderID(), buyOrder->getClientOrderId(), name, buyOrder->getSide(), "Fill", buyOrder->getQuantity(), price, validationMessage);
                        buyOrder->setQuantity(0);
                        buyOrder = buyOrders.erase(buyOrder);
                    }
                    else
                    {
                        transactionRecorder.recordTransaction(buyOrder->getOrderID(), buyOrder->getClientOrderId(), name, buyOrder->getSide(), "PFill", order.getQuantity(), price, validationMessage);
                        buyOrder->setQuantity(buyOrder->getQuantity() - order.getQuantity());
                        buyOrder++;
                    }

                    order.setQuantity(0);
                    break;
                }
                else
                {
                    transactionRecorder.recordTransaction(order.getOrderID(), order.getClientOrderId(), name, order.getSide(), "PFill", buyOrder->getQuantity(), price, validationMessage);

                    transactionRecorder.recordTransaction(buyOrder->getOrderID(), buyOrder->getClientOrderId(), name, buyOrder->getSide(), "Fill", buyOrder->getQuantity(), price, validationMessage);

                    order.setQuantity(order.getQuantity() - buyOrder->getQuantity());
                    buyOrder->setQuantity(0);
                    buyOrder = buyOrders.erase(buyOrder);
                }
            }
            else
            {
                break;
            }
        }
        if (order.getQuantity() > 0)
        {
            if (order.getQuantity() == baseQuantity)
            {
                // status NEW
                transactionRecorder.recordTransaction(order.getOrderID(), order.getClientOrderId(), name, order.getSide(), "New", order.getQuantity(), order.getPrice(), validationMessage);
            }
            OrderBook::insertSellOrder(order);
        }
    }
}

void OrderBook::insertBuyOrder(Order &newOrder)
{
    newOrder.setPriority(1);
    // Check if an object with the same price is already in the vector
    auto it = std::find_if(buyOrders.begin(), buyOrders.end(), [newOrder](const Order &obj)
                           { return obj.getPrice() == newOrder.getPrice(); });

    if (it != buyOrders.end())
    {
        // Order with the same price found
        do
        {
            newOrder.setPriority(it->getPriority() + 1);
            it++;
        } while (it->getPrice() == newOrder.getPrice());
    }

    buyOrders.push_back(newOrder);

    // Sort the vector based on the price and priority attributes
    std::sort(buyOrders.begin(), buyOrders.end(), [](const Order &a, const Order &b)
              {
            if (a.getPrice() != b.getPrice()) {
                return b.getPrice() < a.getPrice();
            } else {
                return a.getPriority() < b.getPriority();
            } });
}

void OrderBook::insertSellOrder(Order &newOrder)
{
    newOrder.setPriority(1);
    // Check if an object with the same price is already in the vector
    auto it = std::find_if(sellOrders.begin(), sellOrders.end(), [newOrder](const Order &obj)
                           { return obj.getPrice() == newOrder.getPrice(); });

    if (it != sellOrders.end())
    {
        // Order with the same price found
        do
        {
            newOrder.setPriority(it->getPriority() + 1);
            it++;
        } while (it->getPrice() == newOrder.getPrice());
    }

    sellOrders.push_back(newOrder);

    // Sort the vector based on the price and priority attributes
    std::sort(sellOrders.begin(), sellOrders.end(), [](const Order &a, const Order &b)
              {
            if (a.getPrice() != b.getPrice()) {
                return b.getPrice() > a.getPrice();
            } else {
                return a.getPriority() < b.getPriority();
            } });
}