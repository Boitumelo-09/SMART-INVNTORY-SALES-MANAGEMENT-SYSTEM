#include "utility.h"
#include <string>
#include <cstdlib>
#include <iostream>

void clearScreen() {
    system(CLEAR_COMMAND);
}
void newLine() {
    std::cout << std::string(2, '\n');
}
void pressToContinue() {
    newLine();
    std::cout << horizontalPadding() << "Press Enter To Proceed...";
    std::cin.get();
    clearScreen();
}

void verticalPadding() {
    std::cout << std::string(5, '\n');
}
std::string horizontalPadding() {
    return  std::string(5, '\t');
}
void exitProgram() {
    clearScreen();
    verticalPadding();
    std::cout << horizontalPadding() << "Exiting System...";
    pressToContinue();
    clearScreen();
    verticalPadding();
    std::cout << horizontalPadding() << "Thank You For Visiting...";
    verticalPadding();
    exit(0);
}
