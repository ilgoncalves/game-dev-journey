#include <iostream>

#include "Person.h"

using std::cout;
using std::endl;

class Student : public Person {
 private:
  int gpa, major;

 public:
  Student(std::string name, int age, std::string addr, int gpa, int major)
      : Person(name, age, addr), gpa(gpa), major(major) {}

  void setName(std::string newName) { Person::setName("Student: " + newName); }
};

int main() {
  Student s("John Doe", 20, "123 Main St", 3, 14);
  s.showData();
  s.setName("Jane Doe");
  s.showData();
  s.Person::setName("New Jonh Doe");
  s.showData();
  return 0;
}