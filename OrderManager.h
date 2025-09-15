#pragma once
#include "utility.h"
#include "Order.h"
#include "Customer.h"
#include "ProductManager.h"
#include <vector>

class OrderManager {
    std::vector<Order> orders;
public:
    const std::vector<Order>& getOrders() const;
    void createOrder(Customer& customer, const ProductManager& productManager);      
    void displayAllOrders() const;
    void displayCustomerOrderSummary(const Customer& customer) const;
    Order* findOrderById(int id);
};
