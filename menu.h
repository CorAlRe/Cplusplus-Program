#ifndef PROJECT_THREE_MENU_H
#define PROJECT_THREE_MENU_H

#include <iostream>
#include "python.h"

using namespace std;

void printMenu(ostream& outStream);
void handleOption(char option, istream& inStream, ostream& outStream);
string getWord(istream& inStream);
void displayFrequency(string item, int frequency, ostream& outStream);


#endif
