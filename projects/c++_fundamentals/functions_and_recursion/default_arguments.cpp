#include <iostream>

using std::cout;
using std::endl;

void power(int base, int exponent = 2) {
  int result = 1;
  for (int i = 1; i <= exponent; i++) {
    result *= base;
  }
  cout << result << endl;
}

int main() {
  power(2, 4);
  power(2, 0);
  return 0;
}