#include "Shape.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;

Shape::Shape(std::string type) : type(type) {}

void Shape::getArea() {}
void Shape::getPerimeter() {}

void Shape::printPerimeter(float perimeter) {
  cout << "Perimeter of " << type << ": " << perimeter << endl;
}

void Shape::printArea(float area) {
  cout << "Area of " << type << ": " << area << endl;
}