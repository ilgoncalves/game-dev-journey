#include <iostream>

#include <string>

using std::cout;
using std::endl;
using std::string;

class Character {};
class Player : public Character {};
class Enemy : public Character {};
class Item {
 private:
  int usage = 100;

 public:
  Item() {  }
  virtual void use() = 0;

  int getUsage() { return usage; }
  void setUsage(int newUsage) { usage = newUsage; }
};

class Weapon: public Item {};
class Potion: public Item {};
class Inventory {};
class GameEvent {};
class GameTimeline {};
class Level {};

int main() { return 0; }