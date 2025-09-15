#include "utility.h"
#include "OrderManager.h"
#include <string>
#include <iostream>

const std::vector<Order>& OrderManager::getOrders() const { return orders; }

void OrderManager::createOrder(Customer& customer) {
    clearScreen();
    verticalPadding();
    int orderID = static_cast<int>(orders.size()) + 3000;





    orders.push_back(Order(orderID, customer));
    std::cout << horizontalPadding() << "Order Successfully made";
    newLine();
    pressToContinue();
}


void OrderManager::displayAllOrders() const {
    clearScreen();
    verticalPadding();
    std::cout << horizontalPadding() << "Placed Orders";
    newLine();
    for (const auto& order : orders) {
        std::cout << horizontalPadding() << "ORDER ID : " << order.getOrderID();
        newLine();
        std::cout << horizontalPadding() << "CUSTOMER : " << order.getCustomer().getCustomerName();
        newLine();
        std::cout << horizontalPadding() << "TOTAL    : R" << order.getTotalAmount();
        newLine();
    }
    std::cout << horizontalPadding() << std::string(50, '*');
    pressToContinue();
    return;
}

void OrderManager::displayCustomerOrderSummary(const Customer& customer) const {
    clearScreen();
    verticalPadding();
    std::cout << horizontalPadding() << " I N V O I C E ";
    newLine();
    customer.displayCustomer();
    newLine();

    bool found = false;
    for (const auto& order : orders) {
        if (order.getCustomer().getCustomerId() == customer.getCustomerId()) {
            order.displayOrder();
            found = true;
        }
    }
    if (!found) {
        std::cout << horizontalPadding() << "No orders found for this customer.\n";
        pressToContinue();
    }
}

Order* OrderManager::findOrderById(int id) {
    for (auto& order : orders) {
        if (order.getOrderID() == id) return &order;
    }
    return nullptr;
}
