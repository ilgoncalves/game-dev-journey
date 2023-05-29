#ifndef STACK_H
#define STACK_H

#include <vector>

template <typename T>
class Stack {
 private:
  std::vector<T> stackElements;

 public:
  void push(T element);
  T pop();
  bool empty();
};

#include "Stack.tpp"
#endif  // STACK_H
