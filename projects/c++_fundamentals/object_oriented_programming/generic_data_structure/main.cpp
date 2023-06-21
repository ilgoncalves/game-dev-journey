#include <exception>
#include <iostream>

template <typename T>
class Node {
 public:
  T data;
  Node<T>* next;
  Node(const T& data) : data(data), next(nullptr) {}
};

// Exception class for empty list
class EmptyListException : public std::exception {
 public:
  const char* what() const throw() { return "List is empty!"; }
};

// LinkedList class
template <typename T>
class LinkedList {
 private:
  Node<T>* head;

 public:
  LinkedList() : head(nullptr) {}

  ~LinkedList() {
    while (head != nullptr) {
      Node<T>* temp = head;
      head = head->next;
      delete temp;
    }
  }

  void add(const T& data) {
    Node<T>* newNode = new Node<T>(data);
    newNode->next = head;
    head = newNode;
  }

  void remove() {
    if (head == nullptr) {
      throw EmptyListException();
    }
    Node<T>* temp = head;
    head = head->next;
    delete temp;
  }

  bool search(const T& data) {
    Node<T>* current = head;
    while (current != nullptr) {
      if (current->data == data) {
        return true;
      }
      current = current->next;
    }
    return false;
  }

  void printList() {
    Node<T>* current = head;
    while (current != nullptr) {
      std::cout << current->data << " ";
      current = current->next;
    }
    std::cout << "\n";
  }
};

int main() {
  LinkedList<int> list;
  try {
    list.add(10);
    list.add(20);
    list.add(30);
    list.printList();
    list.remove();
    list.printList();
    std::cout << (list.search(20) ? "Found\n" : "Not Found\n");
    list.remove();
    list.remove();
    list.remove();
  } catch (EmptyListException& e) {
    std::cerr << "Exception: " << e.what() << "\n";
  }
  return 0;
}