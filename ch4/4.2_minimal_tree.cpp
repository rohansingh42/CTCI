#include <algorithm>
#include "Node.hpp"

std::shared_ptr<Node<int>> minTree (
    std::vector<int>::iterator begin,
    std::vector<int>::iterator end) {
  int vec_size = begin - end;
  if (vec_size == 0) {
    return nullptr;
  } else if (vec_size == 1) {
    std::shared_ptr<Node<int>> node =
      std::make_shared<Node<int>>(Node<int>(*begin));
    return node;
  } else {
    int mid = vec_size/2;
    std::shared_ptr<Node<int>> node =
      std::make_shared<Node<int>>(Node<int>(*(begin + mid)));
    node->left = minTree(begin, begin + mid);
    node->right = minTree(begin + mid + 1, end);
    return node;
  }
}

int main() {
  int num;
  std::vector<int> array;
  std::cout << "Enter nums for array : ";
  while (std::cin >> num) {
    array.push_back(num);
  }
  std::cin.clear();
  std::sort(array.begin(), array.end());
  std::shared_ptr<Node<int>> root = minTree(array.begin(), array.end());
  printTree<int>(root);
  return 0;
}
