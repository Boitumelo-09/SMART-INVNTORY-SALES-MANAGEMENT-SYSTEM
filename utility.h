#pragma once
#include<string>

#ifndef UTILITY_H
#define UTILITY_H


#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif
void clearScreen();
void newLine();
void pressToContinue();

std::string horizontalPadding();

void verticalPadding();
void exitProgram();
void clearInputBuffer();
#endif
