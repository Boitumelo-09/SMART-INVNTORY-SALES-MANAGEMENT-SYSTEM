#pragma once
#include "utility.h"
#include "Order.h"
#include "Customer.h"
#include <vector>

class OrderManager {
    std::vector<Order> orders;
public:
    const std::vector<Order>& getOrders() const;
    void createOrder(Customer& customer);      // creates empty order (keeps old behavior)
    void addOrder(const Order& order);         // add a fully-built order created by customer
    void displayAllOrders() const;
    void displayCustomerOrderSummary(const Customer& customer) const;
    Order* findOrderById(int id);
};
