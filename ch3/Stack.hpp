#pragma once 

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "Node.hpp"

class Stack {
  std::shared_ptr<Node> head;

 public:
  Stack() : head(nullptr), length(0) {}

  Stack(std::shared_ptr<Node> head) :
        head(head) {}

  std::shared_ptr<Node> peek() {
    return head;
  }

  int getLength() {
    std::shared_ptr<Node> l(head);
    int length = 0;
    while (l != nullptr) {
      l = l->next;
      length++;
    }
    return length;
  }

  void push(int data) {
    std::shared_ptr<Node> newPtr = 
      std::make_shared<Node>(Node(data));
    newPtr->next = head
    head = newPtr;
  }

  void push(std::shared_ptr<Node> newPtr) {
    newPtr->next = head
    head = newPtr;
  }

  std::shared_ptr<Node> pop() {
    if (head == nullptr) {
      return nullptr;
    } else {
      head = head->next;
      return head;
    }
  }

  bool isEmpty() {
    return (head == nullptr);
  }

  void print() {
    if (head != nullptr) {
      std::shared_ptr<Node> temp(head);
      while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
      }
    }
    std::cout << "NULL" << std::endl;
  }
};
