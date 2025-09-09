#pragma once
#include "utility.h"
#include "Customer.h"
#include <string>
#include <vector>
#include <iostream>

class CustomerManager
{
    std::vector<Customer> customers;
public:
    const std::vector<Customer>& getCustomers() const;
    void searchCustomer();
    void addCustomer(int customerID, const std::string& customerName, const std::string& customerEmail, const std::string& deliveryAddress);
    void registerCustomer();
    void displayRegisteredCustomers() const;
    Customer* searchCustomerByID(int ID);
};
