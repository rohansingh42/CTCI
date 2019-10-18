#include "linkedList.hpp"

void deleteMiddleNode(std::shared_ptr<Node> delNode) {
  if (delNode->next == nullptr) {
  } else {
    delNode->data = delNode->next->data;
    delNode->next = delNode->next->next;
  }
}

int main() {
  LinkedList l;
  int num;
  int k;
  std::cout << "Enter nums for list : ";
  while (std::cin >> num) {
    l.addToTail(num);
  }
  std::cin.clear();
  std::cout << "Enter position of node to delete : ";
  std::cin >> k;
  l.printList();
  std::shared_ptr<Node> temp(l.getHead());
  for (int i = 1; i < k; i++) {
    temp = temp->next;
  }
  deleteMiddleNode(temp);
  l.printList();
  return 0;
}
