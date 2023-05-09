#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

const int YEAR_IN_DAYS = 365;

void print(string customString) { cout << customString + "\n"; }

int main() {
  string firstName, lastName;
  int age;

  print("Type your first name: ");
  cin >> firstName;
  print("Type your last name: ");
  cin >> lastName;
  print("Type your age: ");
  cin >> age;

  double ageInDays = YEAR_IN_DAYS * age;

  print(firstName + " " + lastName + " has lived for " +
        std::to_string((int)ageInDays) + " days.\n");

  return 0;
}