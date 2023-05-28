#include <iostream>

#include "Vector.h"

using std::cout;
using std::endl;

class SuperVector : public Vector {
 public:
  SuperVector(double x = 0.0, double y = 0.0) : Vector(x, y) {}
  Vector operator+=(Vector& rhs) {
    this->x += rhs.x;
    this->y += rhs.y;
    return *this;
  }
};

int main() {
  SuperVector v1(2, 3);

  Vector v2(5, 2);

  v1 += v2;

  cout << v1.x << endl;
  cout << v1.y << endl;

  return 0;
}