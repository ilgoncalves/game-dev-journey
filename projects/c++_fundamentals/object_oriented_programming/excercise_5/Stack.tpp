#include "Stack.h"

using std::cout;
using std::endl;

template <typename T>
void Stack<T>::push(T element) {
  stackElements.push_back(element);
}

template <typename T>
T Stack<T>::pop() {
  if (stackElements.empty()) {
    cout << "Stack is empty" << endl;
    break;
  }
  T tmp = stackElements.back();
  stackElements.pop_back();
  return tmp;
}

template <typename T>
bool Stack<T>::empty() {
  return stackElements.empty();
}