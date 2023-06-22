#include <iostream>

using std::cout;
using std::endl;

class Character {};
class Player : public Character {};
class Enemy : public Character {};
class Item {};
class Weapon: public Item {};
class Potion: public Item {};
class Inventory {};
class GameEvent {};
class GameTimeline {};
class Level {};

int main() { return 0; }