#include <iostream>

#include "Character.h"

using std::cout;
using std::endl;

class Warrior : public Character {
 public:
  Warrior(string name) : Character(name){};

  void attack(Character& enemy) { enemy.receiveAttack(*this); };
  void defend() {
    cout << "Warrior " << name << " defended the attack" << endl;
  };
  void move(){};
};

class Mage : public Character {};

class Archer : public Character {};

int main() {
  Warrior warrior1("Igor");

  Warrior warrior2("thomas");

  warrior1.attack(warrior2);

  warrior2.displayLife();

  warrior1.attack(warrior2);

  warrior2.displayLife();
  return 0;
}