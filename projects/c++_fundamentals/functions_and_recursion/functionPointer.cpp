#include <iostream>

using std::cout;
using std::endl;

int add(int x, int y) { return x + y; }

int main() {
  int (*functionPointer)(int a, int b);

  functionPointer = add;

  cout << functionPointer(10, 20) << endl;

  return 0;
}