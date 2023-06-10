#include <iostream>
#include <random>
#include <sstream>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::vector;

string generate_uuid_v4() {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  static std::uniform_int_distribution<> dis(0, 15);
  static std::uniform_int_distribution<> dis2(8, 11);
  stringstream ss;
  int i;
  ss << std::hex;
  for (i = 0; i < 8; i++) {
    ss << dis(gen);
  }
  ss << "-";
  for (i = 0; i < 4; i++) {
    ss << dis(gen);
  }
  ss << "-4";
  for (i = 0; i < 3; i++) {
    ss << dis(gen);
  }
  ss << "-";
  ss << dis2(gen);
  for (i = 0; i < 3; i++) {
    ss << dis(gen);
  }
  ss << "-";
  for (i = 0; i < 12; i++) {
    ss << dis(gen);
  };
  return ss.str();
}

class Item {
 private:
  int usage = 100;
  string id;

 public:
  Item() { id = generate_uuid_v4(); }
  virtual void use() = 0;

  int getUsage() { return usage; }
  void setUsage(int newUsage) { usage = newUsage; }
};

class Potion : public Item {
 public:
  void use() {
    if (this->getUsage() > 0) {
      this->setUsage(0);
    } else {
      cout << "this potion is already used" << endl;
    }
  }
};

class Weapon : public Item {
 public:
  void use() {
    if (this->getUsage() <= 0) {
      cout << "this Weapon is broken" << endl;
      return;
    }
    int amountUsed = this->getUsage() - 10;
    if (amountUsed > 0) {
      this->setUsage(amountUsed);
    } else {
      this->setUsage(0);
    }
  }
};

class Armor : public Item {
 public:
  void use() {
    if (this->getUsage() <= 0) {
      cout << "this Armor is broken" << endl;
      return;
    }
    int amountUsed = this->getUsage() - 20;
    if (amountUsed > 0) {
      this->setUsage(amountUsed);
    } else {
      this->setUsage(0);
    }
  }
};

class Inventory {
 private:
  vector<Item> itens;

 public:
  void add(Item item){};

  void remove(Item item){};

  void use(Item item){};
};

int main() {
  Potion potion;
  Weapon weapon;
  Armor armor;

  return 0;
}