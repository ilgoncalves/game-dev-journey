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

  virtual void attack() = 0;
  virtual void defend() = 0;
  virtual void move() = 0;
};

#endif  // CHARACTER_H
