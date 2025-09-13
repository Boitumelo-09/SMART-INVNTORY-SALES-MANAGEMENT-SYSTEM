#include "utility.h"
#include "Product.h"
#include "ProductManager.h"
#include <string>

#include <iostream>

ProductManager::ProductManager() {

    products.push_back(Product(1001, "T-Shirt", "Clothing", 149.99, 50));
    products.push_back(Product(1002, "Jeans", "Clothing", 499.50, 30));
    products.push_back(Product(1003, "Sneakers", "Clothing", 899.99, 20));
    products.push_back(Product(1004, "Leather Jacket", "Clothing", 1499.00, 10));
    products.push_back(Product(1005, "Cap", "Clothing", 199.99, 40));
                               
    products.push_back(Product(1006, "Wireless Earbuds", "Electronics", 799.00, 25));
    products.push_back(Product(1007, "Smartphone", "Electronics", 6999.99, 15));
    products.push_back(Product(1008, "Laptop", "Electronics", 11999.99, 8));
    products.push_back(Product(1009, "Smartwatch", "Electronics", 2499.99, 12));
    products.push_back(Product(1010, "Gaming Headset", "Electronics", 1299.00, 18));
                               
    products.push_back(Product(1011, "Backpack", "Accessories", 349.75, 25));
    products.push_back(Product(1012, "Wallet", "Accessories", 249.99, 30));
    products.push_back(Product(1013, "Sunglasses", "Accessories", 599.50, 20));
    products.push_back(Product(1014, "Wristwatch", "Accessories", 999.00, 15));
    products.push_back(Product(1015, "Belt", "Accessories", 179.99, 35));
                               
    products.push_back(Product(1016, "Coffee Maker", "Home & Lifestyle", 899.00, 10));
    products.push_back(Product(1017, "Desk Lamp", "Home & Lifestyle", 299.99, 20));
    products.push_back(Product(1018, "Electric Kettle", "Home & Lifestyle", 399.50, 18));
    products.push_back(Product(1019, "Vacuum Cleaner", "Home & Lifestyle", 1899.99, 8));
    products.push_back(Product(1020, "Air Fryer", "Home & Lifestyle", 1499.00, 12));

}
void ProductManager::displayProducts() const{
    clearScreen();
    verticalPadding();
    std::cout << horizontalPadding() <<" A V A I L A B L E - P R O D U C T S ";
    for (auto& singleProduct : products)
    {
        newLine();
        std::cout << horizontalPadding() << " ID        : " << singleProduct.getProductID();
        newLine();
        std::cout << horizontalPadding() << " NAME      : " << singleProduct.getProductName();
        newLine();
        std::cout << horizontalPadding() << " CATEGORY  : " << singleProduct.getProductCategory();
        newLine();
        std::cout << horizontalPadding() << " PRICE     : " << singleProduct.getProductPrice();
        newLine();
        std::cout << horizontalPadding() << " AVAILABLE : " << singleProduct.getQuantity();
        newLine();
        std::cout << horizontalPadding() << std::string(50, '*');
    }
    newLine();
    newLine();
    pressToContinue();
    return;
}
    
Product* ProductManager::findProductById(int id) {
    for (auto& product_ADDRESS : products) {
        if (id == product_ADDRESS.getProductID())
        {
            return &product_ADDRESS;
        }
    }
    return nullptr;
}
const std::vector<Product>& ProductManager::getProducts() const { return products; }

void ProductManager::searchProduct() {
    int searchId{0};
    clearScreen();
    verticalPadding();
    std::cout << horizontalPadding() << "SEARCHING PRODUCT";
    newLine();
    newLine();
    std::cout << horizontalPadding() << "Product ID : ";
    std::cin >> searchId;
    clearBuffer();
    Product* ptrToProduct = findProductById(searchId);
         
    if (ptrToProduct)
    {
        clearScreen();
        verticalPadding();
        std::cout << horizontalPadding() << "Product Found!!";
        newLine();
        std::cout << horizontalPadding() << "PRODUCT INFORMATION";
        newLine();
        newLine();
        std::cout << horizontalPadding() << " ID        : " << ptrToProduct->getProductID();
        newLine();                                            
        std::cout << horizontalPadding() << " NAME      : " << ptrToProduct->getProductName();
        newLine();                                            
        std::cout << horizontalPadding() << " CATEGORY  : " << ptrToProduct->getProductCategory();
        newLine();                                            
        std::cout << horizontalPadding() << " PRICE     : " << ptrToProduct->getProductPrice();
        newLine();                                            
        std::cout << horizontalPadding() << " AVAILABLE : " << ptrToProduct->getQuantity();
        newLine();
        std::cout << horizontalPadding() << std::string(50, '*');
        pressToContinue();
        return;
    }
    else {
        clearScreen();
        verticalPadding();
        std::cout << horizontalPadding() << "Product With ID : " << searchId << ", Is Not In Our Database.";
        newLine();
        pressToContinue();
        return;
    }

}