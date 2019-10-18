#include "linkedList.hpp"

int returnKthToLast(LinkedList l, int k) {
  if (l.getHead() == nullptr) {
    return 0;
  } else if (k < 1) {
    return 0;
  } else if (l.getLength() < k) {
    return (l.getHead())->data;
  } else {
    std::shared_ptr<Node> runner(l.getHead());
    for (int i = 1; i <= (l.getLength() - k); i++) {
      runner = runner->next;
    }
    return runner->data;
  }
}

int main() {
  LinkedList l;
  int num;
  int k;
  int data;
  std::cout << "Enter nums for list : ";
  while (std::cin >> num) {
    l.addToTail(num);
  }
  std::cin.clear();
  std::cout << "Enter k : ";
  std::cin >> k;
  l.printList();
  data = returnKthToLast(l, k);
  std::cout << "The kth to last element is : " << data << std::endl;
  return 0;
}
