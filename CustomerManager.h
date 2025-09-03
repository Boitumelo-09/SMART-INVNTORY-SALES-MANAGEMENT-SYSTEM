#pragma once
#include "utility.h"
#include "Customer.h"
#include <string>
#include <vector>
#include <iostream>
class CustomerManager
{
	std::vector<Customer>customers;
public:

	const std::vector<Customer> getCustomers();
	void searchCustomer();
	void addCustomer();
	void registerCustomer();
	Customer* searchCustomerByID(int ID);
};

