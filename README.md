# 🛒 E-Commerce Management System (C++)

This project is a **console-based e-commerce management system** built
in **C++ using Object-Oriented Programming (OOP)**.\
It simulates the workflow of a small online shop, allowing you to manage
**customers, products, and orders** in a modular and scalable way.

------------------------------------------------------------------------

## ✨ Features

-   **Customer Management**
    -   Register new customers
    -   View customer details
    -   Search customers by ID
-   **Product Management**
    -   Add new products
    -   Display all available products
    -   Search products by ID
-   **Order Management**
    -   Create new orders for registered customers
    -   Track and update order status
    -   View all orders in the system
-   **System Controller**
    -   Centralized `System` class that connects all managers
    -   Easy-to-navigate menus
    -   Continuous program loop until exit

------------------------------------------------------------------------

## 🗂️ Project Structure

``` bash
├── include/
│   ├── Customer.h
│   ├── CustomerManager.h
│   ├── Product.h
│   ├── ProductManager.h
│   ├── Order.h
│   ├── OrderManager.h
│   └── System.h
├── src/
│   ├── Customer.cpp
│   ├── CustomerManager.cpp
│   ├── Product.cpp
│   ├── ProductManager.cpp
│   ├── Order.cpp
│   ├── OrderManager.cpp
│   └── System.cpp
└── main.cpp
```

------------------------------------------------------------------------

## 🚀 Getting Started

### 1. Clone the Repository

``` bash
git clone https://github.com/boitumelo-09/SMART-INVNTORY-SALES-MANAGEMENT-SYSTEM.git
cd SMART-INVNTORY-SALES-MANAGEMENT-SYSTEM.cpp
```

### 2. Compile the Project

Use `g++` to compile all source files:

``` bash
g++ src/*.cpp main.cpp -I include -o SMART-INVNTORY-SALES-MANAGEMENT-SYSTEM
```

### 3. Run the Program

``` bash
./SMART-INVNTORY-SALES-MANAGEMENT-SYSTEM
```

------------------------------------------------------------------------

## 🖼️ Demo / Screenshots

### Main Menu

   
        Main Menu
    ==============================
    1. Customers Services
    2. Administration
    3. Orders
    0. Exit
    Choose an option:

### Customer Menu

    --- Customer Menu ---
    1. Add Customer
    2. View Customers
    3. Search Customer by ID
    0. Back

### Product Menu

    --- Product Menu ---
    1. Add Product
    2. View Products
    3. Search Product by ID
    0. Back

### Order Menu

    --- Order Menu ---
    1. Place Order
    2. View Orders
    3. Update Order Status
    0. Back

------------------------------------------------------------------------

## 📚 Concepts Practiced

-   **Object-Oriented Programming (OOP)**
-   **Encapsulation** (using classes, getters, setters)
-   **Composition** (System owns managers, managers own objects)
-   **Code modularization** with `.h` and `.cpp`
-   **Basic Menu-driven navigation**

------------------------------------------------------------------------

## 🔮 Future Improvements

-   [ ] Allow customers to log in and manage their own orders
-   [ ] Add file storage (save/load customers, products, and orders)
-   [ ] Implement product stock updates when orders are placed
-   [ ] Generate sales reports (daily/weekly/monthly)
-   [ ] Add sorting and filtering (e.g., products by price)

------------------------------------------------------------------------

## 🙌 Acknowledgements

This project was built as part of my **C++ OOP learning journey 2025**.\
Special thanks to mentors, peers, and the coding community for
inspiration.
