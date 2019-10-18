#include "linkedList.hpp"

LinkedList removeDuplicates(LinkedList l) {
  if (l.getHead() == nullptr) {
    return l;
  } else {
    std::shared_ptr<Node> slow(l.getHead());
    std::shared_ptr<Node> fast;
    while (slow !=  nullptr) {
      fast = slow->next;
      while (fast != nullptr) {
        if (slow->data == fast->data) {
          l.deleteThis(fast);
        }
        fast = fast->next;
      }
      slow = slow->next;
    }
    return l;
  }
}

int main() {
  LinkedList l;
  int num;
  std::cout << "Enter nums for list : ";
  while (std::cin >> num) {
    l.addToTail(num);
  }
  std::cin.clear();
  l.printList();
  l = removeDuplicates(l);
  l.printList();
  return 0;
}