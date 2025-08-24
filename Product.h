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


};

#endif