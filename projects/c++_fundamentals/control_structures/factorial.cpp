#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int getFactorial(int number) {
  int result = 1;

  for (int i = number; i > 0; i--) {
    result *= i;
  }
  return result;
}

void printFactorial(int number) {
  cout << number << "!";

  if (number > 1) {
    cout << " = ";
    for (int i = number; i > 0; i--) {
      cout << i;
      if (i != 1) {
        cout << " x ";
      }
    }
  }

  cout << " = ";
  cout << getFactorial(number) << endl;
}

int main() {
  for (int i = 0; i <= 10; i++) {
    printFactorial(i);
  }

  return 0;
}
