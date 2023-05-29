#ifndef STACK_H
#define STACK_H

#include <vector>

template <typename T>
class Stack {
 private:
  std::vector<T> stackElement;

 public:
  void push(T element);
  void pop(T element);
  void empty();
};
#endif  // STACK_H
