#include "utility.h"
#include "CustomerManager.h"
#include <string>
#include <iostream>
#include <algorithm>

const std::vector<Customer>& CustomerManager::getCustomers() const { return customers; }

void CustomerManager::searchCustomer() {
    int searchId = 0;
    clearScreen();
    verticalPadding();
    std::cout << horizontalPadding() << "SEARCHING CUSTOMER";
    newLine();
    newLine();
    std::cout << horizontalPadding() << "Customer ID : ";
    std::cin >> searchId;
    Customer* ptrToCustomer = searchCustomerByID(searchId);

    if (ptrToCustomer) {
        clearScreen();
        verticalPadding();
        std::cout << horizontalPadding() << "Customer Found!!";
        newLine();
        std::cout << horizontalPadding() << "CUSTOMER INFORMATION";
        newLine();
        newLine();
        std::cout << horizontalPadding() << " ID      : " << ptrToCustomer->getCustomerId();
        newLine();
        std::cout << horizontalPadding() << " NAME    : " << ptrToCustomer->getCustomerName();
        newLine();
        std::cout << horizontalPadding() << " EMAIL   : " << ptrToCustomer->getCustomerEmail();
        newLine();
        std::cout << horizontalPadding() << " ADDRESS : " << ptrToCustomer->getCustomerAddress();
        newLine();
        std::cout << horizontalPadding() << std::string(50, '*');
        pressToContinue();
        return;
    }
    else {
        clearScreen();
        verticalPadding();
        std::cout << horizontalPadding() << "CUSTOMER : " << searchId << ", Is Not In Our Database.";
        newLine();
        pressToContinue();
        return;
    }
}

void CustomerManager::addCustomer(int customerID, const std::string& customerName, const std::string& customerEmail, const std::string& deliveryAddress) {
    verticalPadding();
    customers.push_back(Customer(customerID, customerName, customerEmail, deliveryAddress));
    std::cout << horizontalPadding() << "Customer " << customerName << " Registered successfully!";
    newLine();
    std::cout<<"Customer ID : "<<customerID;
    pressToContinue();
    return;
}

void CustomerManager::registerCustomer() {
    clearScreen();
    verticalPadding();
    int customerID = static_cast<int>(customers.size()) + 4000;
    std::string regName, regEmail, regAddress;
    std::cout << horizontalPadding() << "CUSTOMER REGISTRATION";
    newLine();
    std::cout << horizontalPadding() << "Enter Username        : ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, regName);
    newLine();
    std::cout << horizontalPadding() << "Enter Email Address   : ";
    std::getline(std::cin, regEmail);
    newLine();
    std::cout << horizontalPadding() << "Enter Physical Address: ";
    std::getline(std::cin, regAddress);
    newLine();
    pressToContinue();
    addCustomer(customerID, regName, regEmail, regAddress);
    return;
}

Customer* CustomerManager::searchCustomerByID(int ID) {
    for (auto& customer : customers) {
        if (ID == customer.getCustomerId()) {
            return &customer;
        }
    }
    return nullptr;
}

void CustomerManager::displayRegisteredCustomers() const {
    clearScreen();
    verticalPadding();
    std::cout << horizontalPadding() << "R E G I S T E R E D - C U S T O M E R S";
    newLine();
    int totalRegisteredCustomers = 0;
    // sort by customer ID before listing (non-modifying view is not possible, we copy if we wanted to avoid changing original)
    std::vector<Customer> sorted = customers;
    std::sort(sorted.begin(), sorted.end(), [](const Customer& a, const Customer& b) {
        return a.getCustomerId() < b.getCustomerId();
        });

    for (auto& singleCustomer : sorted)
    {
        newLine();
        std::cout << horizontalPadding() << " ID      : " << singleCustomer.getCustomerId();
        newLine();
        std::cout << horizontalPadding() << " NAME    : " << singleCustomer.getCustomerName();
        newLine();
        std::cout << horizontalPadding() << " EMAIL   : " << singleCustomer.getCustomerEmail();
        newLine();
        std::cout << horizontalPadding() << " ADDRESS : " << singleCustomer.getCustomerAddress();
        newLine();
        std::cout << horizontalPadding() << std::string(50, '*');
        totalRegisteredCustomers++;
    }
    newLine();
    std::cout << horizontalPadding() << "Total Customers : " << totalRegisteredCustomers;
    newLine();
    pressToContinue();
    return;
}
