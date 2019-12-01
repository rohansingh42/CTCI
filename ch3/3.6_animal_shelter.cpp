#include "Queue.hpp"

class AnimalShelter {
  Queue animals;

 public:
  AnimalShelter() {}

  std::shared_ptr<Node> peek() {
    return animals.peek();
  }

  void enqueue(std::string str) {
    std::shared_ptr<Node> newPtr = 
    std::make_shared<Node>(Node(str));
    animals.add(newPtr);
  }

  std::shared_ptr<Node> pop() {
    return min.pop();
  }

  bool isEmpty() {
    return min.isEmpty();
  }

  void print() {
    min.print();
  }
};

int main() {
  MinStack s;
  int num;
  std::cout << "Enter nums for stack : ";
  while (std::cin >> num) {
    s.push(num);
    s.print();
  }
  std::cin.clear();

  while (s.peek() != nullptr) {
    s.print();
    s.pop();
  }
  return 0;
}
