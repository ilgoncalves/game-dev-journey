#include <iostream>

// Entity base class
class Entity {
 public:
  int position;

  Entity(int pos) : position(pos) {}

  virtual void draw() {
    std::cout << "Drawing an entity at position: " << position << "\n";
  }
};

// Character class
class Character : virtual public Entity {
 public:
  Character(int pos) : Entity(pos) {}

  void draw() override {
    std::cout << "Drawing a character at position: " << position << "\n";
  }
};

// Item class
class Item : virtual public Entity {
 public:
  Item(int pos) : Entity(pos) {}

  void draw() override {
    std::cout << "Drawing an item at position: " << position << "\n";
  }
};

// TreasureGuardian class
class TreasureGuardian : public Character, public Item {
 public:
  TreasureGuardian(int pos) : Entity(pos), Character(pos), Item(pos) {}

  void draw() override {
    std::cout << "Drawing a TreasureGuardian at position: " << position << "\n";
  }
};

// Game class
class Game {
 public:
  void drawEntity(Entity &entity) { entity.draw(); }
};

int main() {
  Game game;

  Character character(1);
  game.drawEntity(character);

  Item item(2);
  game.drawEntity(item);

  TreasureGuardian treasureGuardian(3);
  game.drawEntity(treasureGuardian);

  return 0;
}