#include <ctime>
#include <iostream>
#include <string>

class Record {
 protected:
  int id;
  std::time_t createdAt;
  std::time_t updatedAt;

 public:
  Record(int id) : id(id), createdAt(std::time(0)), updatedAt(std::time(0)) {}

  virtual void save() {
    std::cout << "Saving record with id: " << id << "\n";
    updatedAt = std::time(0);
  }

  virtual void update() {
    std::cout << "Updating record with id: " << id << "\n";
    updatedAt = std::time(0);
  }

  virtual void deleteRecord() {
    std::cout << "Deleting record with id: " << id << "\n";
  }

  int getId() const { return id; }

  std::time_t getCreatedAt() const { return createdAt; }

  std::time_t getUpdatedAt() const { return updatedAt; }
};

class UserRecord : public Record {
 private:
  std::string name;
  std::string email;
  std::string password;

 public:
  UserRecord(int id, std::string name, std::string email, std::string password)
      : Record(id), name(name), email(email), password(password) {}
};

class ProductRecord : public Record {
 private:
  std::string productName;
  double price;
  int quantity;

 public:
  ProductRecord(int id, std::string productName, double price, int quantity)
      : Record(id),
        productName(productName),
        price(price),
        quantity(quantity) {}
};

int main() {
  UserRecord user(1, "John Doe", "johndoe@example.com", "password");
  user.save();
  user.update();
  user.deleteRecord();

  ProductRecord product(2, "Product 1", 100.0, 10);
  product.save();
  product.update();
  product.deleteRecord();

  return 0;
}