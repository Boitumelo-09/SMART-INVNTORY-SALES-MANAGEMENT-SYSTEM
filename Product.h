#pragma once
#include <string>;


#ifndef PRODUCT_H
#define PRODUCT_H

class Product
{
private:
    int productID;
    std::string productName;
    std::string productCategory;
    double productPrice;
    int stockQuantity;

public:
    Product();
    Product(int id, std::string name, std::string category, double price, int quantity);

    void setProductID(int newId);
    void setProductName(std::string newName);
    void setProductCategory(std::string newCategory);
    void setPrice(double newPrice);
    void setQuantity(int neeQuantity);

    int getProductID();
    std::string getProductName();
    std::string getProductCategory();
    double getProductPrice();
    int getQuantity();


};

#endif