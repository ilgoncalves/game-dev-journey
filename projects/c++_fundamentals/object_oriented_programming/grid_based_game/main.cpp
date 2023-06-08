#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

using std::cout;
using std::endl;

class Entity {
 public:
  int id;

  Entity(int id) : id(id) {}
};

class Grid {
 private:
  std::vector<std::vector<std::shared_ptr<Entity>>> grid;

 public:
  Grid(int rows, int columns)
      : grid(rows, std::vector<std::shared_ptr<Entity>>(columns, nullptr)) {}

  std::shared_ptr<Entity>& operator()(int row, int column) {
    if (row < 0 || row >= grid.size() || column < 0 ||
        column >= grid[0].size()) {
      throw std::out_of_range("Index out of range");
    }

    return grid[row][column];
  }
};

int main() {
  Grid grid(10, 10);

  std::shared_ptr<Entity> entity = std::make_shared<Entity>(1);
  std::shared_ptr<Entity> entity2 = std::make_shared<Entity>(7);
  grid(2, 3) = entity;
  grid(2, 7) = entity2;

  std::shared_ptr<Entity> retrievedEntity = grid(2, 3);

  std::shared_ptr<Entity> retrievedEntity2 = grid(2, 7);
  if (retrievedEntity != nullptr) {
    cout << "Entity ID: " << retrievedEntity->id << endl;
  }
  if (retrievedEntity2 != nullptr) {
    cout << "Entity 2 ID: " << retrievedEntity2->id << endl;
  }

  return 0;
}