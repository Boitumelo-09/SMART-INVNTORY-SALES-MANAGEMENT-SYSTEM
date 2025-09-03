#pragma once

#include "Product.h"
#include <vector>
#include <string>

class ProductManager
{
	std::vector<Product>products;
public:
        ProductManager();
        void displayProducts() const;
        Product* findProductById(int id);
        void searchProduct();
        const std::vector<Product>& getProducts() const;
    };



