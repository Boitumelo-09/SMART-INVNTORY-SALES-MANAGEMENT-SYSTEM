#include "utility.h"
#include "Product.h"
#include "Customer.h"
#include "Order.h"
#include <iostream>

Order::Order(int id, Customer& customer) :orderId(id),customer(customer),totalAmount(0),orderStatus("Processing"){}

int         Order::getOrderID() const { return orderId; }
double      Order::getTotalAmount() const { return totalAmount; }
Customer    Order::getCustomer() const { return customer; }
std::string Order::getOrderStatus() const { return orderStatus; }

void Order::setOrderStatus(std::string newStatus) const { newStatus = orderStatus; }
void Order::addToOrder(Product& product){
	itemsInCart.push_back(product);
	totalAmount += product.getProductPrice();
}
void Order::displayOrder() const{
	clearScreen();
	verticalPadding();
	customer.displayCustomer();
	newLine();
	newLine();
	std::cout << horizontalPadding() << " O R D E R - S U M M A R Y ";
	newLine();
	for ( auto &product : itemsInCart)
	{

	}
}
