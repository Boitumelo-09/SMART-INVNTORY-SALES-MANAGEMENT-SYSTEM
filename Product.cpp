#include "utility.h"
#include "Product.h"
#include "string"
#include <iostream>



Product::Product(int id, std::string name, std::string category, double price, int quantity): productID(id) , productName(name),productCategory(category),productPrice(price),stockQuantity(quantity){}

void Product::setProductID(int newId) { newId = productID;}
void Product::setProductName(std::string newName) { newName = productName; }
void Product::setProductCategory(std::string newCategory) { newCategory = productCategory; }
void Product::setPrice(double newPrice) { newPrice = productPrice; }
void Product::setQuantity(int newQuantity) { newQuantity = stockQuantity; }

int Product:: getProductID() const { return productID; }
std::string Product::getProductName() const { return productName; }
std::string Product::getProductCategory() const { return productCategory; }
double Product::getProductPrice() const { return productPrice; }
int Product::getQuantity() const { return stockQuantity; }

void Product::displayProduct() const {
	std::cout << horizontalPadding()<<"PRODUCT ID       : "<<getProductID();
	newLine();
	std::cout << horizontalPadding()<<"PRODUCT NAME     : "<<getProductName();
	newLine();
	std::cout << horizontalPadding()<<"PRODUCT CATEGORY : "<<getProductCategory();
	newLine();
	std::cout << horizontalPadding()<<"PRODUCT PRICE    : "<<getProductPrice();
	newLine();
	std::cout << horizontalPadding() << std::string(50, '*');
	return;
}