
#include <algorithm>
#include <iostream>
#include <random>
#include <sstream>
#include <stdexcept>
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

  string getId() { return id; }
  int getUsage() { return usage; }
  void setUsage(int newUsage) { usage = newUsage; }

  bool operator==(const Item* item) { return item->id == this->id; }
};

class Potion : public Item {
 protected:
  void use() {
    if (this->getUsage() > 0) {
      this->setUsage(0);
      cout << "potion has been used" << endl;
    } else {
      cout << "this potion is already used" << endl;
    }
  }
};

class Weapon : public Item {
 protected:
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
    cout << "Weapon used! life remain:" << this->getUsage() << endl;
  }
};

class Armor : public Item {
 protected:
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
    cout << "Armor used! life remain:" << this->getUsage() << endl;
  }
};

class Inventory {
 private:
  vector<Item*> itens;

 public:
  void add(Item* item) { itens.push_back(item); };

  void remove(Item* item) {
    for (auto it = itens.begin(); it != itens.end();) {
      if (*it == item) {
        itens.erase(it);
      } else {
        it++;
      }
    }
  }

  void size() { cout << "Size is: " << itens.size() << endl; }

  void use(Item* item) {
    bool isItemInArray =
        std::find(std::begin(itens), std::end(itens), item) != std::end(itens);
    if (!isItemInArray) {
      throw std::out_of_range("Item not found ");
    } else {
      item->use();
    }
  };
};

int main() {
  Potion potion;
  Potion potion2;
  Weapon weapon;
  Armor armor;
  Inventory inventory;

  inventory.add(&potion);
  inventory.add(&potion2);
  inventory.size();
  inventory.size();
  inventory.use(&potion2);
  inventory.remove(&potion);
  inventory.size();
  inventory.use(&weapon);

  return 0;
}