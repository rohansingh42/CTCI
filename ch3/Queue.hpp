#pragma once 

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "Node.hpp"

class Queue {
  std::shared_ptr<Node> first;
  std::shared_ptr<Node> last;

 public:
  Queue() : first(nullptr), last(nullptr), length(0) {}

  Queue(std::shared_ptr<Node> first) :
        first(first), last(first){
    if (last != nullptr) {
      while (last->next != nullptr) {
        last = last->next;
      }
    }
  }

  std::shared_ptr<Node> peek() {
    return first;
  }

  int getLength() {
    int length = 0;
    if (head != nullptr) {
      std::shared_ptr<Node> temp(head);
      while (temp != nullptr) {
        temp = temp->next;
        length++;
      }
    }
    return length;
  }

  void add(int data) {
    std::shared_ptr<Node> newPtr = 
      std::make_shared<Node>(Node(data));
    if (last ==  nullptr) {
      last = newPtr;
      head = newPtr;
    } else {
      last->next = newPtr;
      last = newPtr;
    }
  }


  void add(std::shared_ptr<Node> newPtr) {
    if (last ==  nullptr) {
      last = newPtr;
      head = newPtr;
    } else {
      last->next = newPtr;
      last = newPtr;
    }
  }

  std::shared_ptr<Node> remove() {
    if (first != nullptr) {
      first = first->next;
    }
    return first;
  }

  bool isEmpty() {
    return (head == nullptr);
  }
  
  void print() {
    if (first != nullptr) {
      std::shared_ptr<Node> temp(first);
      while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
      }
    }
    std::cout << "NULL" << std::endl;
  }
};