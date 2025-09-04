#include "utility"
#include "CustomerManager.h"
#include <string>
#include <iostream>


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
    std::cout << horizontalPadding()<<"Customer " << customerName << " Registered successfully!";
    newLine();
    pressToContinue();
    return;
}
void CustomerManager::registerCustomer(){
    clearScreen();
    verticalPadding();
    int customerID = customers.size() + 4000;
    std::string regName, regEmail, regAddress;
    std::cout << horizontalPadding() << "CUSTOMER REGISTRATION";
    newLine();
    std::cout << horizontalPadding() << "Enter Username        : ";
    getline(std::cin, regName);
    newLine();
    //must undergo filters and authentication measures(saved for the future)
    std::cout << horizontalPadding() << "Enter Email Adress    : ";
    getline(std::cin, regEmail); 
    newLine();
    //also for future purporses
    std::cout << horizontalPadding() << "Enter Physical Address : ";
    getline(std::cin, regAddress);
    newLine();
    //for future updates
    pressToContinue();
    addCustomer(customerID,regName, regEmail, regAddress);
    return;
}
Customer* CustomerManager::searchCustomerByID(int ID){

    for (auto &customer : customers) {
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
    for (auto& singleCustomer : customers)
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