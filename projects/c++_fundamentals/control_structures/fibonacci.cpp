#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
  int n = 0;
  cout << "Type a number to show 'n' first numbers of Fibonacci series."
       << endl;

  cin >> n;

  cout << endl;
  if (n > 0) {
    long lastNumber = 1, penultNumber = 0;
    for (int i = 1; i <= n; i++) {
      if (i == 1) {
        cout << penultNumber << " ";
        continue;
      }
      if (i == 2) {
        cout << lastNumber << " ";
        continue;
      }

      long sum = lastNumber + penultNumber;
      penultNumber = lastNumber;
      lastNumber = sum;
      cout << sum << " ";
    }
    cout << endl;
  }
}