#pragma once
#include "utility.h"
#include "Order.h"
#include "Customer.h"
#include "Product.h"
#include "vector"
class OrderManager

{
	std::vector<Order> orders;
public:
	const std::vector<Order> getOrders();
	void createOrder();
	void displayAllOrders();
	void displayCustomerOrderSummary();

};

