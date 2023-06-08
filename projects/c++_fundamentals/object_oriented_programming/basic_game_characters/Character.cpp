#include "Character.h"

#include <chrono>
#include <iostream>
#include <random>

using std::cout;
using std::endl;

// Function to generate random strength
int generateRandomStrength(int min_strength, int max_strength) {
  // Obtain a seed from the system clock:
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

  // Using Mersenne Twister algorithm to generate random numbers
  std::mt19937 generator(seed);

  // Using a distribution to transform the random values generated by the
  // Mersenne Twister into an integer range [min_strength, max_strength]
  std::uniform_int_distribution<int> distribution(min_strength, max_strength);

  // Generate a random strength
  return distribution(generator);
}

Character::Character(string name) : name(name) {
  strength = generateRandomStrength(0, 1000);
  cout << "Character successfully created" << endl;

  cout << "Strength: " << strength << endl;
}

void Character::displayLife() {
  cout << this->name << " life: " << health << "%" << endl;
}

int Character::getStrength() { return this->strength; }

int Character::getHealth() { return this->health; }

string Character::getName() { return this->name; }

void Character::setStrength(int newStrength) { this->strength = newStrength; }

void Character::setHealth(int newHealth) { this->health = newHealth; }