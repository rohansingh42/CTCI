#include "Stack.hpp"

class MinStack {
  Stack min;

 public:
  MinStack() {}

  std::shared_ptr<Node> peek() {
    return min.peek();
  }

  int getLength() {
    return min.getLength();
  }

  void push(int data) {
    if (min.peek() == nullptr) {
      min.push(data);
    } else {
      Stack temp;
      std::shared_ptr<Node> head(min.peek());
      while (head != nullptr) {
        if (data > head->data) {
          temp.push(min.pop());
          head = min.peek();
        } else {
          break;
        }
      }
      min.push(data);
      while (temp.peek() != nullptr) {
        min.push(temp.pop());
      }
    }
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
