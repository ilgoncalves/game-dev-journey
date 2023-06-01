#include <iostream>

#include "Bank.h"

using std::cout;
using std::endl;

void updateBalance(Bank& bank, int newBalance) { bank.balance = newBalance; }

int main() {
  Bank account("Igor");

  account.showBalance();

  updateBalance(account, 20);
  account.showBalance();
  return 0;
}