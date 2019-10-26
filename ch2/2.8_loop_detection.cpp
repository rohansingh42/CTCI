#include "linkedList.hpp"

std::shared_ptr<Node> getCycleStart(LinkedList& l) {
  std::shared_ptr<Node> r(l.getHead());
  std::shared_ptr<Node> s(l.getHead());
  std::shared_ptr<Node> cn(l.getHead());
  std::shared_ptr<Node> tn(l.getHead());

  bool flag = true;
  while (flag) {
    r = r->next->next;
    s = s->next;
    if (r == nullptr || r->next == nullptr) {
      flag = false;
      return nullptr;
    }
    if (s == r) {
      flag = false;
      cn = s;
    }
  }
  while (cn != tn) {
    tn = tn->next;
    cn = cn->next;
  }
  return cn;
}

int main() {
  LinkedList l;
  int num;
  int pos = -1;
  std::cout << "Enter nums for list : ";
  while (std::cin >> num) {
    l.addToTail(num);
  }
  std::cin.clear();

  std::cout << "Enter position for cycle : ";
  std::cin >> pos;

  if (pos > 0 && pos <= l.getLength()) {
    std::shared_ptr<Node> r(l.getHead());
    for (int i = 1; i < pos; i++) {
      r = r->next;
    }
    std::shared_ptr<Node> t(l.getTail());
    t->next = r;
  }

  std::shared_ptr<Node> cycleNode = getCycleStart(l);
  if (cycleNode != nullptr) {
    std::cout << "Cycle starts at node  : " << cycleNode->data << std::endl;
    std::shared_ptr<Node> p(l.getHead());
    int flag = 0;
    while (flag != 2) {
      std::cout << p->data << " -> ";
      if (p == cycleNode) {
        flag++;
      }
      p = p->next;
    }
    std::cout << std::endl;
  } else {
    std::cout << "NULLLLLL " << std::endl;
  }
  return 0;
}
