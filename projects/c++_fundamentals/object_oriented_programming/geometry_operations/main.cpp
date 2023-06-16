#include <iostream>

class Point {
 public:
  int x, y;

  Point(int x = 0, int y = 0) : x(x), y(y) {}

  Point operator+(const Point& point) const {
    return Point(x + point.x, y + point.y);
  }

  Point operator-(const Point& point) const {
    return Point(x - point.x, y - point.y);
  }

  bool operator==(const Point& point) const {
    return x == point.x && y == point.y;
  }

  bool operator!=(const Point& point) const { return !(*this == point); }
};

class Point3D : public Point {
 public:
  int z;

  Point3D(int x = 0, int y = 0, int z = 0) : Point(x, y), z(z) {}

  Point3D operator+(const Point3D& point) const {
    Point p = Point(this->x, this->y) + Point(point.x, point.y);
    return Point3D(p.x, p.y, z + point.z);
  }

  Point3D operator-(const Point3D& point) const {
    return Point3D(x - point.x, y - point.y, z - point.z);
  }

  bool operator==(const Point3D& point) const {
    return x == point.x && y == point.y && z == point.z;
  }

  bool operator!=(const Point3D& point) const { return !(*this == point); }
};

int main() {
  Point p1(1, 2), p2(3, 4);
  Point p3 = p1 + p2;
  std::cout << "p3: (" << p3.x << ", " << p3.y << ")\n";

  Point3D p4(1, 2, 3), p5(4, 5, 6);
  Point3D p6 = p4 + p5;
  std::cout << "p6: (" << p6.x << ", " << p6.y << ", " << p6.z << ")\n";

  return 0;
}