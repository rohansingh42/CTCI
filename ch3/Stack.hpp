#pragma once 

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "Node.hpp"

class Stack {
  std::shared_ptr<Node> head;
  std::shared_ptr<Node> minHead;

 public:
  Stack() : head(nullptr), minHead(nullptr) {}

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
    std::shared_ptr<Node> newMinPtr = 
      std::make_shared<Node>(Node(data));

    newPtr->next = head;
    head = newPtr;

    if ((minHead == nullptr) ||
        (minHead->data >= newMinPtr->data)) {
      newMinPtr->next = minHead;
      minHead = newMinPtr;
    }
  }

  void push(std::shared_ptr<Node> newPtr) {
    std::shared_ptr<Node> newMinPtr = 
          std::make_shared<Node>(Node(newPtr->data));
    newPtr->next = head;
    head = newPtr;

    if ((minHead == nullptr) ||
        (minHead->data >= newMinPtr->data)) {
      newMinPtr->next = minHead;
      minHead = newMinPtr;
    }
  }

  std::shared_ptr<Node> pop() {
    if (head == nullptr) {
      return nullptr;
    } else {
      if (minHead->data == head->data) {
        minHead = minHead->next;
      }
      std::shared_ptr<Node> poppedNode = 
      std::make_shared<Node>(Node(head->data));
      head = head->next;
      return poppedNode;
    }
  }

  bool isEmpty() {
    return (head == nullptr);
  }

  int getMin() {
    if (minHead == nullptr) {
      return -1;
    } else {
      return minHead->data;
    }
  }

  void print() {
    if (head != nullptr) {
      std::shared_ptr<Node> temp(head);
      while (temp != nullptr) {
        std::cout << temp->data << " <- ";
        temp = temp->next;
      }
      std::cout << std::endl;
    } else {
      std::cout << "NULL" << std::endl;
    }
  }
};
