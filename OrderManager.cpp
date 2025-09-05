#include "utility.h"
#include "OrderManager.h"
#include "Customer.h"
#include <string>
#include <iostream>


const std::vector<Order> OrderManager::getOrders() { return orders; }
void OrderManager::createOrder(Customer& customer){
	clearScreen();
	verticalPadding();
	int orderID = orders.size() + 3000;
	orders.push_back(Order(orderID, customer));
	std::cout << horizontalPadding() << "Order Successfully made";

}
void OrderManager::displayAllOrders(){
	clearScreen();
	verticalPadding();
	std::cout << horizontalPadding() << "Placed Orders";
	newLine();
	for (const auto& order : orders) {
		std::cout << horizontalPadding() << "ORDER ID : " << order.getOrderID();
		newLine();
		std::cout << horizontalPadding() << "CUSTOMER : " << order.getCustomer().getCustomerName();
		newLine();
		std::cout << horizontalPadding() << "TOTAL    : " << order.getTotalAmount();
		newLine();

	}
	std::cout << horizontalPadding() << std::string(50, '*');
	pressToContinue();
	return;
}
void OrderManager::displayCustomerOrderSummary(Customer&customer){
	clearScreen();
	verticalPadding();
	std::cout << horizontalPadding() << " I N V O I C E ";
	newLine();
	customer.displayCustomer();
	displayAllOrders();


}