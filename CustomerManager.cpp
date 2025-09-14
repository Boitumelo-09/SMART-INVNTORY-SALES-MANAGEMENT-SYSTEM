#include "utility.h"
#include "CustomerManager.h"
#include <string>
#include <iomanip>         
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
    std::cin.ignore();
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
    std::cout<<horizontalPadding()<<"Customer ID : "<<customerID;
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

#include <iomanip>  // for setw, left

void CustomerManager::displayRegisteredCustomers() const {
    clearScreen();
    verticalPadding();
    std::cout << horizontalPadding()
        << "R E G I S T E R E D - C U S T O M E R S";
    newLine();
    newLine();

    if (customers.empty()) {
        std::cout << horizontalPadding() << "404, No Registered Customers";
        newLine();
        pressToContinue();
        return;
    }

    // Print table header
    std::cout << horizontalPadding()
        << std::left << std::setw(6) << "ID"
        << std::setw(20) << "NAME"
        << std::setw(25) << "EMAIL"
        << std::setw(30) << "ADDRESS";
    newLine();

    std::cout << horizontalPadding()
        << std::string(85, '-') << "\n";

    int totalRegisteredCustomers = 0;

    // Print each customer
    for (const auto& singleCustomer : customers) {
        std::cout << horizontalPadding()
            << std::left << std::setw(6) << singleCustomer.getCustomerId()
            << std::setw(20) << singleCustomer.getCustomerName()
            << std::setw(25) << singleCustomer.getCustomerEmail()
            << std::setw(30) << singleCustomer.getCustomerAddress()
            << "\n";

        totalRegisteredCustomers++;
    }

    newLine();
    std::cout << horizontalPadding()
        << "Total Customers : " << totalRegisteredCustomers;
    newLine();
    pressToContinue();
}

