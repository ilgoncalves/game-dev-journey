#include <iostream>

using std::cout;
using std::endl;

class Person {
 private:
  std::string name, address;
  int age;

 public:
  void showData() {
    cout << name << " -- " << age << " -- " << address << endl;
  }

  void setAge(int newAge) { age = newAge; }
  void setAddress(std::string newAddress) { address = newAddress; }
  void setName(std::string newName) { name = newName; }
  Person(std::string n, int a, std::string addr = "")
      : name(n), age(a), address(addr) {}
};

int main() {
  Person p1("Igor", 24);

  p1.setAddress("Main street, 124");

  p1.showData();

  p1.setAge(25);

  p1.showData();

  p1.setName("Igor Gonçalves");

  p1.showData();
  return 0;
}