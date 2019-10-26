#include "linkedList.hpp"

std::shared_ptr<Node> getCommonNode(LinkedList& l1, LinkedList& l2) {
  std::shared_ptr<Node> r1(l1.getHead());
  std::shared_ptr<Node> r2(l2.getHead());
  if (r1 == nullptr || r2 == nullptr) {
    return nullptr;
  }
  int s1 = 1;
  int s2 = 1;
  int count = 0;
  while (r1->next != nullptr) {
    r1 = r1->next;
    s1++;
  }
  while (r2->next != nullptr) {
    r2 = r2->next;
    s2++;
  }
  if (r1 != r2) {
    return nullptr;
  }
  r1 = l1.getHead();
  r2 = l2.getHead();
  if (s1 > s2) {
    while (count < (s1 - s2)) {
      r1 = r1->next;
      count++;
    }
  } else {
    while (count < (s2 - s1)) {
      r2 = r2->next;
      count++;
    }
  }
  while (r1->next != nullptr) {
    if (r1 == r2) {
      return r1;
    }
    r1 = r1->next;
    r2 = r2->next;
  }
  return nullptr;
}

int main() {
  LinkedList l1;
  LinkedList l2;
  LinkedList l3;
  int num;
  std::cout << "Enter nums for list 1 : ";
  while (std::cin >> num) {
    l1.addToTail(num);
  }
  std::cin.clear();
  std::cout << "Enter nums for list 2 : ";
  while (std::cin >> num) {
    l2.addToTail(num);
  }
  std::cin.clear();
  std::cout << "Enter nums for list 3 : ";
  while (std::cin >> num) {
    l3.addToTail(num);
  }
  std::cin.clear();

  l1.addToTail(l3.getHead());
  l2.addToTail(l3.getHead());

  l1.printList();
  l2.printList();
  l3.printList();

  std::shared_ptr<Node> commonNode = getCommonNode(l1, l2);
  if (commonNode != nullptr) {
    std::cout << "Common node data is : " << commonNode->data << std::endl;
  } else {
    std::cout << "NULLLLLL " << std::endl;
  }
  return 0;
}
