
#pragma once
#include <vector>
#include <string>
#include "Product.h"
#include "Customer.h"

class Order {
private:
    int orderId;                  // Unique order ID
    Customer customer;            // Who placed it
    std::vector<Product> items;   // Products in this order
    double totalAmount;           // Sum of products
    std::string status;           // Pending / Shipped / Delivered
    std::string orderDate;        // Optional timestamp

public:
    // ==========================
    // Customer Methods (what they can do)
    // ==========================

    // Display their order
    void displayOrder() const;

    // View total amount
    double getTotalAmount() const;

    // Check status
    std::string getStatus() const;

    // Get ordered products
    std::vector<Product> getProducts() const;

    // ==========================
    // Admin / System Methods (what management does)
    // ==========================

    // Constructor (system creates the order)
    Order(int id, const Customer& cust, const std::vector<Product>& items);

    // Add product to the order (if editing)
    void addProduct(const Product& product);

    // Remove product from the order
    void removeProduct(int productId);

    // Recalculate total amount
    void calculateTotal();

    // Update order status
    void setStatus(const std::string& newStatus);

    // Get order ID
    int getOrderId() const;

    // Get customer details
    Customer getCustomer() const;
};


