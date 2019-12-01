#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <string>

template <typename T> struct Node {
  T data;
  std::vector<std::shared_ptr<Node>> children;
  std::shared_ptr<Node> parent;
  std::shared_ptr<Node> left;
  std::shared_ptr<Node> right;

  Node(T data) :
        data(data), parent(nullptr), left(nullptr), right(nullptr) {}

  Node(T data, std::shared_ptr<Node> parent) :
        data(data), parent(parent) {}

  bool operator > (const T &t) {
    return data > t;
  }

  bool operator == (const T &t) {
    return data == t;
  }

  bool operator < (const T &t) {
    return data < t;
  }
};

template <typename T> void printTree (
          std::shared_ptr<Node<T>> root) {
  std::vector<std::shared_ptr<Node<T>>> curr;
  curr.push_back(root);
  while (curr.size() != 0) {
    std::vector<std::shared_ptr<Node<T>>> next;
    for (auto cn : curr) {
      std::cout << cn->data << " | ";
      if (cn->left != nullptr) {
        next.push_back(cn->left);
      }
      if (cn->right != nullptr) {
        next.push_back(cn->right);
      }
    }
    std::cout << std::endl;
    curr = next;
  }
}
