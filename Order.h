#pragma once
#include <vector>
#include <string>
#include "Product.h"
#include "Customer.h"

class Order {
    int orderId;
    Customer customer;
    std::vector<Product> itemsInCart;
    double totalAmount;
    std::string orderStatus;
public:
    Order(int id, Customer& customer);

    int getOrderID() const;
    double getTotalAmount() const;
    const Customer& getCustomer() const;
    std::string getOrderStatus() const;

    void setOrderStatus(const std::string& newStatus);
    void addToOrder(const Product& product);
    void displayOrder() const;
};
