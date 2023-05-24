#include "Person.h"

#include <iostream>

using std::cout;
using std::endl;

Person::Person(std::string n, int a, std::string addr)
    : name(n), age(a), address(addr) {}

void Person::showData() {
  cout << name << " -- " << age << " -- " << address << endl;
}

void Person::setAge(int newAge) { age = newAge; }

void Person::setAddress(std::string newAddress) { address = newAddress; }

void Person::setName(std::string newName) { name = newName; }