#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
 private:
  std::string name, address;
  int age;

 public:
  Person(std::string n, int a, std::string addr = "");

  virtual void showData();
  virtual void setAge(int newAge);
  virtual void setAddress(std::string newAddress);
  virtual void setName(std::string newName);
};

#endif  // PERSON_H