#include <iostream>

using std::cout;
using std::endl;

void swap(int* a, int* b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}

int main() {
  int x = 4;
  int y = 9;
  cout << "X = " << x << endl;
  cout << "Y = " << y << endl;

  swap(&x, &y);

  cout << "Swapped X = " << x << endl;
  cout << "Swapped Y = " << y << endl;

  return 0;
}