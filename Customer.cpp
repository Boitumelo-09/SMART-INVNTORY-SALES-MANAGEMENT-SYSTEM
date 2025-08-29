#include "Customer.h"
#include "utility.h"
#include <string>
#include <iostream>


Customer::Customer(int customerID, std::string& customerName, std::string& customerEmail, std::string& deliveryAddress): customerID(customerID) , customerName(customerName) , customerEmail(customerEmail) , deliveryAddress(deliveryAddress){}

int Customer::getCustomerId() const { return customerID; }
std::string Customer::getCustomerName() const { return customerName; }
std::string Customer::getCustomerEmail() const { return customerEmail; }
std::string Customer::getCustomerAddress() const { return deliveryAddress; }

void Customer::setCustomerName(const std::string& newName) { customerName = newName; }
void Customer::setCustomerEmail(const std::string& newEmail) { customerEmail = newEmail; }
void Customer::setCustomerAddress(const std::string& newAddress) {  deliveryAddress = newAddress; }


void Customer::displayCustomer() const {
	clearScreen();
	verticalPadding();
	std::cout << horizontalPadding() << "Customer Information";
	newLine();  
	std::cout << horizontalPadding() << "CUSTOMER ID      : " << getCustomerId();
	newLine();
	std::cout << horizontalPadding() << "CUSTOMER NAME    : " << getCustomerName();
	newLine();
	std::cout << horizontalPadding() << "EMAIL ADDRESS    : " << getCustomerEmail();
	newLine(); 
	std::cout << horizontalPadding() << "DELIVERY ADDRESS : " << getCustomerAddress();
	newLine();
	std::cout << horizontalPadding() << "*********************************************" << getCustomerAddress();
	newLine();
	newLine();
	pressToContinue();
	return;	
}
