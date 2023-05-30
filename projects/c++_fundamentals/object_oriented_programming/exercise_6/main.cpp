#include <iostream>
#include <stdexcept>

#include "../exercise_5/Stack.h"

using std::cout;
using std::endl;

int main() {
  try {
    Stack<int> stack;

    stack.push(3);
    stack.pop();
    stack.pop();

  } catch (std::out_of_range& err) {
    cout << "Error Caught: " << err.what() << endl;
  }

  return 0;
}