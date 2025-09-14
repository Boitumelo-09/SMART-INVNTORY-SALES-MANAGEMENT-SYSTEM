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
                               
    products.push_back(Product(1016, "Coffee Maker", "Home & Style", 899.00, 10));
    products.push_back(Product(1017, "Desk Lamp", "Home & Style", 299.99, 20));
    products.push_back(Product(1018, "Electric Kettle", "Home & Style", 399.50, 18));
    products.push_back(Product(1019, "Vacuum Cleaner", "Home & Style", 1899.99, 8));
    products.push_back(Product(1020, "Air Fryer", "Home & Style", 1499.00, 12));

}
#include <iomanip>  // for setw, left, right

void ProductManager::displayProducts() const {
    clearScreen();
    verticalPadding();

    std::cout << horizontalPadding()
        << " A V A I L A B L E - P R O D U C T S ";
    newLine();
    newLine();

    // Print table header
    std::cout << horizontalPadding()
        << std::left << std::setw(6) << "ID"
        << std::setw(20) << "NAME"
        << std::setw(15) << "CATEGORY"
        << std::setw(10) << "PRICE"
        << std::setw(12) << "AVAILABLE";
    newLine();

    std::cout << horizontalPadding()
        << std::string(65, '-') << "\n";

    // Print each product in a row
    for (const auto& singleProduct : products) {
        std::cout << horizontalPadding()
            << std::left << std::setw(6) << singleProduct.getProductID()
            << std::setw(20) << singleProduct.getProductName()
            << std::setw(15) << singleProduct.getProductCategory()
            << std::setw(10) << singleProduct.getProductPrice()
            << std::setw(12) << singleProduct.getQuantity()
            << "\n";
    }

    newLine();
    pressToContinue();
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