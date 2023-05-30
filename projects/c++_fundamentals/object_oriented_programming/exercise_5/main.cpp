#include <iostream>

#include "Stack.h"

using std::cout;
using std::endl;

int main() {
  Stack<int> s;

  s.push(3);
  s.push(2);
  s.push(1);

  cout << "Is empty?" << s.empty() << endl;
  s.pop();
  s.pop();
  s.pop();
  cout << "Now, is empty?" << s.empty() << endl;
  s.pop();

  return 0;
}