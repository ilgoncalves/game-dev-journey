#include <iostream>

using std::cout;
using std::endl;

class Student {
 private:
  int studentId;

 public:
  Student(int studentId) : studentId(studentId) {}

  void learn() { cout << "Learning" << endl; }
  void getId() { cout << studentId << endl; }
};

class Employee {
 private:
  int employeeId;

 public:
  Employee(int employeeId) : employeeId(employeeId) {}

  void teach() { cout << "Teaching" << endl; }

  void getId() { cout << employeeId << endl; }
};

class TeachingAssistant : public Employee, public Student {
 public:
  TeachingAssistant(int id) : Student(id), Employee(id) {}

  void getId() {
    Employee::getId();
    Student::getId();
  }
};

int main() {
  TeachingAssistant tA1(19);

  tA1.learn();
  tA1.teach();
  tA1.getId();
  return 0;
}