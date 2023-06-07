#include <iostream>
#include <random>

#include "Character.h"

using std::cout;
using std::endl;

class Warrior : public Character {
 public:
  Warrior(string name) : Character(name){};

  void attack(Character& enemy) {
    int damage = enemy.getStrength() - this->strength;

    if (damage >= 0) {
      int enemyHealth = enemy.getHealth();
      enemy.setHealth(enemyHealth -
                      (damage > enemyHealth ? enemyHealth : damage));

      cout << "Successful attack" << endl;
      cout << "Damage: " << damage << endl;

    } else {
      enemy.defend();
    }
  };
  void defend() {
    cout << "Warrior " << name << " defended the attack" << endl;
  };
  void move() { cout << "Moving like a Warrior" << endl; };
};

class Mage : public Character {
 private:
  double hitKilldamageChance;

 public:
  Mage(string name) : Character(name) {
    hitKilldamageChance = this->strength / 10;
  };
  void attack(Character& enemy) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);

    double minimalCritical = dis(gen);

    if ((1 - minimalCritical) < (hitKilldamageChance / 100)) {
      cout << "Mage " << name << " cursed a critical spell and kill "
           << enemy.getName() << endl;
      enemy.setHealth(0);
    }
  };
  void defend() { cout << "Mage " << name << " defended the attack" << endl; };
  void move() { cout << "Moving like a Mage" << endl; };
};

class Archer : public Character {
 private:
  int arrowQuiver;
  double arrowDamage;

 public:
  Archer(string name) : Character(name) {
    arrowQuiver = 10;
    arrowDamage = this->strength / 100;
  };

  void attack(Character& enemy) {
    for (int i = 0; i <= arrowQuiver; i++) {
      std::random_device rd;
      std::mt19937 gen(rd());
      std::uniform_int_distribution<> dis(0, 1);

      bool arrowReachedEnemy = dis(gen);

      if (arrowReachedEnemy) {
        cout << "An arrow hit " << enemy.getName() << endl;
        cout << "Damage: " << arrowDamage << endl;
        enemy.setHealth(enemy.getHealth() - arrowDamage);
      }
    }
  };

  void defend() {
    cout << "Archer " << name << " defended the attack" << endl;
  };
  void move() { cout << "Moving like a Archer" << endl; };
};

int main() {
  Mage mage("Alex");

  Warrior warrior2("Thomas");

  mage.attack(warrior2);

  warrior2.displayLife();

  mage.attack(warrior2);

  warrior2.displayLife();
  Archer archer1("Edison");

  archer1.attack(mage);

  mage.displayLife();

  return 0;
}
