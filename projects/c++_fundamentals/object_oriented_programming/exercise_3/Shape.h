#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape {
 private:
  std::string type;

 protected:
  void printPerimeter(float perimeter);
  void printArea(float area);

 public:
  Shape(std::string type);

  virtual void getPerimeter() = 0;
  virtual void getArea() = 0;
};

#endif
