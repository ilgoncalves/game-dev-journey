#include <iostream>

// Abstract base class Level
class Level {
 public:
  virtual void play() = 0;  // Pure virtual function
};

// Level1
class Level1 : public Level {
 public:
  void play() override { std::cout << "Playing Level 1" << std::endl; }
};

// Level2
class Level2 : public Level {
 public:
  void play() override { std::cout << "Playing Level 2" << std::endl; }
};

// Game class
class Game {
 private:
  Level* currentLevel;

 public:
  void setLevel(Level* level) { currentLevel = level; }

  void play() {
    if (currentLevel != nullptr) {
      currentLevel->play();
    } else {
      std::cout << "No level set." << std::endl;
    }
  }
};

int main() {
  Game game;

  Level1 level1;
  game.setLevel(&level1);
  game.play();

  Level2 level2;
  game.setLevel(&level2);
  game.play();

  return 0;
}