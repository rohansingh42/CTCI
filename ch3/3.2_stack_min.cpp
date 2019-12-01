#include "Stack.hpp"

int main() {
  Stack s;
  int num;
  std::cout << "Enter nums for stack : ";
  while (std::cin >> num) {
    s.push(num);
  }
  std::cin.clear();

  while (s.peek() != nullptr) {
    s.print();
    std::cout << std::endl;
    std::cout << "Min is : " << s.getMin();
    std::cout << std::endl;
    s.pop();
  }
  return 0;
}
