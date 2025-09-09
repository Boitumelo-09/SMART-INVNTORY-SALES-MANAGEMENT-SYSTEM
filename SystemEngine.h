#pragma once

#include "utility.h"
#include "ProductManager.h"
#include "CustomerManager.h"
#include "OrderManager.h"
#include <iostream>

class System
{
    ProductManager productManager;
    CustomerManager customerManager;
    OrderManager orderManager;

public:
    System();

    void run();                 
private:
    void mainMenu();             
    void customerMenu();         // Customer operations
    void productMenu();          // Product operations
    void orderMenu();            // Order operations
};
