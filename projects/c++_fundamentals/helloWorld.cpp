#include <iostream>
#include <string>

int main()
{
  std::string name;
  std::cout << "Type your name!\n";
  std::cin >> name;

  std::cout << "\nHello World " + name + "!\n";

  return 0;
}