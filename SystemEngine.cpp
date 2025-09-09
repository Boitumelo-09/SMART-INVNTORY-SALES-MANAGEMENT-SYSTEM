#include "SystemEngine.h"

System::System() {
    // You can load sample data here if needed
}

void System::run() {
    while (true) {
        mainMenu();
    }
}

void System::mainMenu() {
    clearScreen();
    verticalPadding();
    std::cout << horizontalPadding() << "==== M A I N - M E N U ====";
    newLine();
    std::cout << horizontalPadding() << "1. Customer Operations";
    newLine();
    std::cout << horizontalPadding() << "2. Product Operations";
    newLine();
    std::cout << horizontalPadding() << "3. Order Operations";
    newLine();
    std::cout << horizontalPadding() << "4. Exit";
    newLine();
    newLine();
    std::cout << horizontalPadding() << "Choose Option: ";

    int choice;
    std::cin >> choice;
    std::cin.ignore(); // flush newline

    switch (choice) {
    case 1: customerMenu(); break;
    case 2: productMenu(); break;
    case 3: orderMenu(); break;
    case 4: exitProgram(); break;
    default:
        std::cout << horizontalPadding() << "Invalid choice!";
        pressToContinue();
        break;
    }
}

void System::customerMenu() {
    clearScreen();
    verticalPadding();
    std::cout << horizontalPadding() << " C U S T O M E R - M E N U ";
    newLine();
    std::cout << horizontalPadding() << "1. Register Customer";
    newLine();
    std::cout << horizontalPadding() << "2. Search Customer";
    newLine();
    std::cout << horizontalPadding() << "3. Display Customers";
    newLine();
    std::cout << horizontalPadding() << "4. Back";
    newLine();
    newLine();
    std::cout << horizontalPadding() << "Choose Option: ";

    int choice;
    std::cin >> choice;
    std::cin.ignore();

    switch (choice) {
    case 1: customerManager.registerCustomer(); break;
    case 2: customerManager.searchCustomer(); break;
    case 3: customerManager.displayRegisteredCustomers(); break;
    case 4: return;
    default:
        std::cout << horizontalPadding() << "Invalid choice!";
        pressToContinue();
        break;
    }
}

void System::productMenu() {
    clearScreen();
    verticalPadding();
    std::cout << horizontalPadding() << " P R O D U C T - M E N U ";
    newLine();
    std::cout << horizontalPadding() << "1. Display Products";
    newLine();
    std::cout << horizontalPadding() << "2. Search Product";
    newLine();
    std::cout << horizontalPadding() << "3. Back";
    newLine();
    newLine();
    std::cout << horizontalPadding() << "Choose Option: ";

    int choice;
    std::cin >> choice;
    std::cin.ignore();

    switch (choice) {
    case 1: productManager.displayProducts(); break;
    case 2: productManager.searchProduct(); break;
    case 3: return;
    default:
        std::cout << horizontalPadding() << "Invalid choice!";
        pressToContinue();
        break;
    }
}

void System::orderMenu() {
    clearScreen();
    verticalPadding();
    std::cout << horizontalPadding() << "O R D E R - M E N U ";
    newLine();
    std::cout << horizontalPadding() << "1. Create Order";
    newLine();
    std::cout << horizontalPadding() << "2. Display All Orders";
    newLine();
    std::cout << horizontalPadding() << "3. Back";
    newLine();
    newLine();
    std::cout << horizontalPadding() << "Choose Option: ";

    int choice;
    std::cin >> choice;
    std::cin.ignore();

    switch (choice) {
    case 1: {
        int customerID;
        clearScreen();
        verticalPadding();
        std::cout << horizontalPadding() << "Enter Customer ID: ";
        std::cin >> customerID;
        std::cin.ignore();

        Customer* c = customerManager.searchCustomerByID(customerID);
        if (c) {
            orderManager.createOrder(*c);
        }
        else {
            std::cout << horizontalPadding() << "Customer not found!";
            pressToContinue();
        }
        break;
    }
    case 2: orderManager.displayAllOrders(); break;
    case 3: return;
    default:
        std::cout << horizontalPadding() << "Invalid choice!";
        pressToContinue();
        break;
    }
}
