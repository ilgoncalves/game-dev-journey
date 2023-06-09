#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using std::string;

class Character {
 protected:
  string name;
  int health = 100, strength;

 public:
  Character(string name);

  virtual void attack(Character& enemy) = 0;
  virtual void defend() = 0;
  virtual void move() = 0;

  int getStrength();

  int getHealth();

  string getName();

  void setStrength(int newStrength);

  void setHealth(int newHealth);

  void displayLife();
};

#endif  // CHARACTER_H
