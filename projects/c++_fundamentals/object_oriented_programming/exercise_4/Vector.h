#ifndef VECTOR_H
#define VECTOR_H

class Vector {
 public:
  double x, y;

  Vector(double x = 0.0, double y = 0.0);

  // Overload + for vector addition
  Vector operator+(const Vector& rhs);

  // Overload - for vector subtraction
  Vector operator-(const Vector& rhs);

  Vector operator*(const Vector& rhs);
  // Overload * for scalar multiplication
  Vector operator*(double rhs);
};
#endif  // VECTOR_H
