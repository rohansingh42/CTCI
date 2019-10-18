#include "linkedList.hpp"

bool recHelper(std::shared_ptr<Node>& first, std::shared_ptr<Node>& last) {
  if (last->next == nullptr) {
    return first->data == last->data;
  }
  bool prevCheck = recHelper(first, last->next);
  first = first->next;
  if (prevCheck) {
    return first->data == last->data;
  } else {
    return false;
  }
}

bool checkPalindrome(LinkedList& l) {
  std::shared_ptr<Node> fast(l.getHead()), slow(l.getHead()), head(l.getHead());
  while (fast != nullptr) {
    if (fast->next == nullptr) {
      fast = fast->next;
    } else {
      fast = fast->next->next;
    }
    slow = slow->next;
  }
  return recHelper(head, slow);
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
  std::cout << "Is Palindrome : " << checkPalindrome(l) << std::endl;
  return 0;
}
