#include <iostream>

#include "Vector.h"

using std::cout;
using std::endl;

class SuperVector : public Vector {
 public:
  SuperVector(double x = 0.0, double y = 0.0) : Vector(x, y) {}
  SuperVector(const Vector& v) : Vector(v.x, v.y) {}  // new constructor

  SuperVector& operator+=(const SuperVector& rhs) {
    this->x += rhs.x;
    this->y += rhs.y;
    return *this;
  }

  SuperVector& operator-=(const SuperVector& rhs) {
    this->x -= rhs.x;
    this->y -= rhs.y;
    return *this;
  }

  SuperVector& operator*=(double rhs) {
    this->x *= rhs;
    this->y *= rhs;
    return *this;
  }

  bool operator==(const SuperVector& rhs) {
    return this->x == rhs.x && this->y == rhs.y;
  }
};

int main() {
  SuperVector v1(2.0, 3.0);
  SuperVector v2(1.0, 1.0);

  cout << "Vector methods" << endl;
  cout << endl;

  SuperVector v3 = v1 + v2 + v2;
  cout << "Expected output: (4, 5) - Output: "
       << "v1 + v2 + v2: (" << v3.x << ", " << v3.y << ")" << endl;

  SuperVector v4 = v1 - v2;
  cout << "Expected output: (1, 2) - Output: "
       << "v1 - v2: (" << v4.x << ", " << v4.y << ")" << endl;

  SuperVector v5 = v1 * v2;
  cout << "Expected output: (2, 3) - Output: "
       << "v1 * v2: (" << v5.x << ", " << v5.y << ")" << endl;

  cout << endl;
  cout << "Super Vector methods" << endl;
  cout << endl;
  v1 += v2;
  cout << "Expected output: (3, 4) - Output: "
       << "v1 += v2: (" << v1.x << ", " << v1.y << ")" << endl;

  v1 -= v2;
  cout << "Expected output: (2, 3) - Output: "
       << "v1 -= v2: (" << v1.x << ", " << v1.y << ")" << endl;

  v1 *= 2.0;
  cout << "Expected output: (4, 6) - Output: "
       << "v1 *= 2: (" << v1.x << ", " << v1.y << ")" << endl;

  bool areEqual = v1 == v2;
  cout << "Expected output: False - Output: "
       << "v1 == v2: " << (areEqual ? "True" : "False") << endl;
  return 0;
}