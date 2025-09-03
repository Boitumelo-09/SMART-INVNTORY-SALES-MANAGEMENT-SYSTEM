#include "utility"
#include "CustomerManager.h"
#include <string>
#include <iostream>
#include <cctype>
#include <limits>

const std::vector<Customer> CustomerManager::getCustomers() { return customers; }
void CustomerManager::searchCustomer(){
    int searchId = 0;
    clearScreen();
    verticalPadding();
    std::cout << horizontalPadding() << "SEARCHING CUSTOMER";
    newLine();
    newLine();
    std::cout << horizontalPadding() << "Customer ID : ";
    std::cin >> searchId;
    Customer* ptrToCustomer = searchCustomerByID(searchId);

    if (ptrToCustomer)
    {
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

void CustomerManager::addCustomer(int customerID, std::string& customerName, std::string& customerEmail, std::string& deliveryAddress) {
    int customerID = customers.size() + 4000; 
    customers.push_back(Customer(customerID, customerName, customerEmail, deliveryAddress));
    std::cout << "Customer " << customerName << " Registered successfully!";
    newLine();
    pressToContinue();
    return;
}
void CustomerManager::registerCustomer(){
    clearScreen();
    verticalPadding();
    std::string newName, newEmail, newAddress;
    std::cout << horizontalPadding() << "CUSTOMER REGISTRATION";
    newLine();
    //deadly measures
}
Customer* CustomerManager::searchCustomerByID(int ID){

    for (auto &customer : customers) {
        if (ID == customer.getCustomerId()) {
            return &customer;
        }
    }
    return nullptr;
}