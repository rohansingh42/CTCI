#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <string>

struct Node {
  int data;
  std::string str;
  std::shared_ptr<Node> next;

  Node(int data) :
        data(data), next(nullptr) {}

  Node(int data, std::string str) :
        data(data), str(str), next(nullptr) {}

  Node(int data, std::string str, std::shared_ptr<Node> next) :
        data(data), str(str), next(next) {}
};
