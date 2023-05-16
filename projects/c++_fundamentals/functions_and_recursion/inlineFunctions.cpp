#include <iostream>

using std::cout;
using std::endl;

inline int max(int a, int b) { return a > b ? a : b; }

int main() {
  cout << "The max value is: " << max(123, 1) << endl;
  cout << max(1, 2) << endl;
  return 0;
}