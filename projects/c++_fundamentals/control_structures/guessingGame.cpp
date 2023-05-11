#include <chrono>
#include <iostream>
#include <random>

using std::cin;
using std::cout;
using std::endl;
using std::chrono::system_clock;

int generateRandomNumber() {
  std::random_device rd;
  std::mt19937 gen(rd());

  std::uniform_int_distribution<> dis(0, 100);

  return dis(gen);
}

int main() {
  int randomNumber = generateRandomNumber();
  int chosenNumber;

  do {
    cout << "Type a number between 0 and 100: ";
    cin >> chosenNumber;

    if (chosenNumber < randomNumber) {
      cout << "Too low" << endl;
    } else if (chosenNumber > randomNumber) {
      cout << "Too high" << endl;
    }

  } while (randomNumber != chosenNumber);

  cout << "Congrats! You Win!"
       << " Random number is: " << randomNumber << endl;

  return 0;
}
