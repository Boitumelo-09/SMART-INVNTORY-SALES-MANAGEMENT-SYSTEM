#include "utility.h"
#include "Product.h"
#include "Customer.h"
#include "Order.h"
#include <iostream>

Order::Order(int id, Customer& customer) : orderId(id), customer(customer), totalAmount(0), orderStatus("Processing") {}
void Order::addProduct(Product* product, int qty) {
	for (int i = 0; i < qty; i++) {
		itemsInCart.push_back(*product);
		totalAmount += product->getProductPrice();
	}
    return;
}
int Order::getOrderID() const { return orderId; }
double Order::getTotalAmount() const { return totalAmount; }
const Customer& Order::getCustomer() const { return customer; }
std::string Order::getOrderStatus() const { return orderStatus; }

void Order::setOrderStatus(const std::string& newStatus) { orderStatus = newStatus; }

void Order::addToOrder(const Product& product) {
    itemsInCart.push_back(product);
    totalAmount += product.getProductPrice();
}

void Order::displayOrder() const {
    clearScreen();
    verticalPadding();
    std::cout << horizontalPadding() << " O R D E R - S U M M A R Y ";
    newLine();
    std::cout << horizontalPadding() << "Order ID : " << getOrderID();
    newLine();
    std::cout << horizontalPadding() << "Customer : " << customer.getCustomerName();
    newLine();
    std::cout << horizontalPadding() << "Status   : " << getOrderStatus();
    newLine();
    std::cout << horizontalPadding() << "Items:";
    newLine();
    for (const auto& product : itemsInCart) {
        product.displayProduct();
    }
    std::cout << horizontalPadding() << " Total Price  : R" << getTotalAmount();
    newLine();
    pressToContinue();
    return;
}
