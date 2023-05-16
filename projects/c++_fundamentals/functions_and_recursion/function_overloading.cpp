#include <iostream>

using std::cout;
using std::endl;

const double PI = 3.14;

void printArea(double circleRadius) {
  double circleArea = PI * circleRadius * circleRadius;
  cout << "The circle area is " << circleArea << endl;
}

void printArea(double width, double length) {
  cout << "The rectangle area is " << width * length << endl;
}

int main() {
  printArea(2.5);
  printArea(2.5, 2.1);
  return 0;
}