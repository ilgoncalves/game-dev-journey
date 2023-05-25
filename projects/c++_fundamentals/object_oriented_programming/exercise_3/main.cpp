
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <vector>

#include "Shape.h"

using std::cout;
using std::endl;
using std::vector;

class Rectangle : public Shape {
 private:
  float width, height;

 public:
  Rectangle(float width, float height)
      : Shape("rectangle"), width(width), height(height){};

  void getPerimeter() { printPerimeter(2 * (width + height)); };
  void getArea() { printArea(width * height); };
};

class Circle : public Shape {
  float radius;

 public:
  Circle(float radius) : Shape("circle"), radius(radius){};

  void getPerimeter() { printPerimeter(2 * M_PI * radius); };
  void getArea() { printArea(M_PI * (radius * radius)); };
};

class Triangle : public Shape {
 private:
  float base, height;

 public:
  Triangle(float base, float height)
      : Shape("triangle"), base(base), height(height){};

  void getPerimeter() {
    float hypotenuse = sqrtf((base * base) + (height * height));
    printPerimeter(hypotenuse + base + height);
  };

  void getArea() { printArea((base * height) / 2); };
};

int main() {
  Triangle t(3, 5);
  Rectangle r(2, 2);
  Circle c(3);

  vector<Shape *> shapes;

  shapes.push_back(&t);
  shapes.push_back(&r);
  shapes.push_back(&c);

  for (Shape *shape : shapes) {
    shape->getArea();
    shape->getPerimeter();
    cout << endl;
  }

  return 0;
}
