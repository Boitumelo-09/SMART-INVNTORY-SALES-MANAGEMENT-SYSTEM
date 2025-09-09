#include "utility.h"
#include "Product.h"
#include <string>
#include <iostream>

Product::Product(int id, std::string name, std::string category, double price, int quantity)
    : productID(id), productName(name), productCategory(category), productPrice(price), stockQuantity(quantity) {
}

void Product::setProductID(int newId) { productID = newId; }
void Product::setProductName(std::string newName) { productName = newName; }
void Product::setProductCategory(std::string newCategory) { productCategory = newCategory; }
void Product::setPrice(double newPrice) { productPrice = newPrice; }
void Product::setQuantity(int newQuantity) { stockQuantity = newQuantity; }

int Product::getProductID() const { return productID; }
std::string Product::getProductName() const { return productName; }
std::string Product::getProductCategory() const { return productCategory; }
double Product::getProductPrice() const { return productPrice; }
int Product::getQuantity() const { return stockQuantity; }

void Product::displayProduct() const {
    std::cout << horizontalPadding() << "PRODUCT ID       : " << getProductID();
    newLine();
    std::cout << horizontalPadding() << "PRODUCT NAME     : " << getProductName();
    newLine();
    std::cout << horizontalPadding() << "PRODUCT CATEGORY : " << getProductCategory();
    newLine();
    std::cout << horizontalPadding() << "PRODUCT PRICE    : " << getProductPrice();
    newLine();
    std::cout << horizontalPadding() << "PRODUCT STOCK    : " << getQuantity();
    newLine();
    std::cout << horizontalPadding() << std::string(50, '*');
    return;
}
