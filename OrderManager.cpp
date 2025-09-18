#include "utility.h"
#include "OrderManager.h"
#include <string>
#include <iostream>

const std::vector<Order>& OrderManager::getOrders() const { return orders; }
	

void OrderManager::createOrder(Customer& customer) {
    ProductManager productManager;  
    int qty{ 0 };
    int productID{0};
    clearScreen();
    verticalPadding();
    std::cout << horizontalPadding() << "C R E A T E - O R D E R";
	newLine();
	newLine();
   
	newLine();
    int orderID = static_cast<int>(orders.size()) + 3000;
    Order newOrder(orderID, customer);
    bool shopping = true;
    while (shopping) {
            productManager.displayProducts();
            newLine();
          
std::cout<< horizontalPadding() << "Enter Product ID: ";
			std::cin >> productID;
            clearBuffer();
            if (productID == 0) {
                shopping = false;
                break;
            }
            else{
          
           Product* product = productManager.findProductById(productID);
           if (!product) {
               std::cout << horizontalPadding() << "Invalid Product ID.\n";
               continue;
           }
          
               
               std::cout << horizontalPadding() << "Enter quantity: ";
               std::cin >> qty;
               clearBuffer();

               if (qty > 0 && qty <= product->getQuantity()) {
                   newOrder.addProduct(product, qty);  
                   product->setQuantity(product->getQuantity() - qty); 
                   std::cout << horizontalPadding() << "Added " << qty
                       << " x " << product->getProductName() << " to order.\n";
               }
               else {
                   std::cout << horizontalPadding() << "Invalid quantity.\n";
               }
           
            }

    }
        
    orders.push_back(newOrder);
    std::cout << horizontalPadding() << "Order Successfully made";
    newLine();
    pressToContinue();
}


void OrderManager::displayAllOrders() const {
    clearScreen();
    verticalPadding();
        if(orders.empty()){
            std::cout << horizontalPadding() << std::string(50, '*');
			std::cout << horizontalPadding() << "No orders placed yet.";
			newLine();
            std::cout << horizontalPadding() << std::string(50, '*');
            pressToContinue();
			return;

        }else{
            std::cout << horizontalPadding() << "Placed Orders";
            newLine();
            std::cout << horizontalPadding() << std::string(50, '*');
            newLine();
            for (const auto& order : orders) {
                std::cout << horizontalPadding() << "ORDER ID : " << order.getOrderID();
                newLine();
                std::cout << horizontalPadding() << "CUSTOMER : " << order.getCustomer().getCustomerName();
                newLine();
                std::cout << horizontalPadding() << "TOTAL    : R" << order.getTotalAmount();
                newLine();
            }
        }
    
    std::cout << horizontalPadding() << std::string(50, '*');
    pressToContinue();
    return;
}

void OrderManager::displayCustomerOrderSummary(const Customer& customer) const {
    clearScreen();
    verticalPadding();
    std::cout << horizontalPadding() << " I N V O I C E ";
    newLine();
    customer.displayCustomer();
    newLine();

    bool found = false;
    for (const auto& order : orders) {
        if (order.getCustomer().getCustomerId() == customer.getCustomerId()) {
            order.displayOrder();
            found = true;
        }
    }
    if (!found) {
        std::cout << horizontalPadding() << "No orders found for this customer.\n";
        pressToContinue();
    }
}

Order* OrderManager::findOrderById(int id) {
    for (auto& order : orders) {
        if (order.getOrderID() == id) return &order;
    }
    return nullptr;
}
