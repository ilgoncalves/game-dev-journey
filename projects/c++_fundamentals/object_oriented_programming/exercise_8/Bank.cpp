#include "Bank.h"

#include <iostream>

using std::cout;
using std::endl;

Bank::Bank(string name) : name(name) {}

void Bank::showBalance() { cout << "Balance: " << balance << endl; }
