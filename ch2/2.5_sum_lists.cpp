#include "linkedList.hpp"

LinkedList sumLists(LinkedList& l1, LinkedList& l2) {
  int sum = 0, carry = 0;
  LinkedList ls;
  std::shared_ptr<Node> p1(l1.getHead()), p2(l2.getHead());
  while (p1 != nullptr || p2 != nullptr) {
    if (p1 == nullptr) {
      ls.addToTail((p2->data + carry) % 10);
      carry = (p2->data + carry) / 10;
      p2 = p2->next;
    } else if (p2 == nullptr) {
      ls.addToTail((p1->data + carry) % 10);
      carry = (p1->data + carry) / 10;
      p1 = p1->next;
    } else {
      sum = p1->data + p2->data;
      ls.addToTail((sum + carry) % 10);
      carry = (sum + carry) / 10;
      p1 = p1->next;
      p2 = p2->next;
    } 
  }
  if (carry != 0) {
    ls.addToTail(carry);
  }
  return ls;
}

int main() {
  LinkedList l1, l2, ls;
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

  ls = sumLists(l1, l2);
  l1.printList();
  l2.printList();
  std::cout << "Sum List : ";
  ls.printList();
  return 0;
}
