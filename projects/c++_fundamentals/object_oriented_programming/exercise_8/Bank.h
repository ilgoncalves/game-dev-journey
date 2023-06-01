#ifndef BANK_H
#define BANK_H
#include <string>

using std::string;
class Bank {
 private:
  int balance = 0;
  string name;

 public:
  Bank(string name);

  void showBalance();

  friend void updateBalance(Bank& bank, int newBalance);
};
#endif  // BANK_H
