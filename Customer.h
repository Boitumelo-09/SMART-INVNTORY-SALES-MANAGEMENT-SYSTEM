#pragma once
#include <string>

class Customer
{
    int customerID;
    std::string customerName;
    std::string customerEmail;
    std::string deliveryAddress;
public:
    Customer(int customerID, const std::string& customerName, const std::string& customerEmail, const std::string& deliveryAddress);

    int getCustomerId() const;
    std::string getCustomerName() const;
    std::string getCustomerEmail() const;
    std::string getCustomerAddress() const;

    void setCustomerName(const std::string& newName);
    void setCustomerEmail(const std::string& newEmail);
    void setCustomerAddress(const std::string& newAddress);
    void displayCustomer() const;
};
