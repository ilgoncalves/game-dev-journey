#include "Vector.h"

Vector::Vector(double x, double y) : x(x), y(y) {}

Vector Vector::operator*(double rhs) {
  return Vector(this->x * rhs, this->y * rhs);
}

Vector Vector::operator+(const Vector& rhs) {
  return Vector(this->x + rhs.x, this->y + rhs.y);
}

Vector Vector::operator-(const Vector& rhs) {
  return Vector(this->x - rhs.x, this->y - rhs.y);
}

Vector Vector::operator*(const Vector& rhs) {
  return Vector(this->x * rhs.x, this->y * rhs.y);
}