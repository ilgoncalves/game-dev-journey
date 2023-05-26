#include <iostream>

#include "Vector.h"

using std::cout;
using std::endl;

int main() {
  Vector v1(2, 3);
  Vector v2(5, 2);
  Vector v3(2, 5);

  Vector v4 = v1 * v2 + v1;

  cout << v4.x << endl;
  cout << v4.y << endl;

  return 0;
}