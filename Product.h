#pragma once
#include <string>


#ifndef PRODUCT_H
#define PRODUCT_H

class Product
{

    int productID;
    std::string productName;
    std::string productCategory;
    double productPrice;
    int stockQuantity;

public:
    
    Product(int id, std::string name, std::string category, double price, int quantity);

    void setProductID(int newId);
    void setProductName(std::string newName);
    void setProductCategory(std::string newCategory);
    void setPrice(double newPrice);
    void setQuantity(int newQuantity);
    void displayProduct() const;
    int getProductID() const;
    std::string getProductName() const;
    std::string getProductCategory() const;
    double getProductPrice() const;
    int getQuantity() const;
};

#endif