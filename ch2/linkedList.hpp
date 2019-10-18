// #pragma once

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

class LinkedList {
  std::shared_ptr<Node> head;
  std::shared_ptr<Node> tail;
  int length;

 public:
  LinkedList() : head(nullptr), tail(nullptr), length(0) {}

  LinkedList(std::shared_ptr<Node> head) :
        head(head), tail(head){
    if (tail == nullptr) {
      length = 0;
    } else {
      length = 1;
      while (tail->next != nullptr) {
        length++;
        tail = tail->next;
      }
    }
  }

  std::shared_ptr<Node> getHead() {
    return head;
  }

  std::shared_ptr<Node> getTail() {
    return tail;
  }

  int getLength() {
    return length;
  }

  void addToTail(int data) {
    std::shared_ptr<Node> newPtr = 
      std::make_shared<Node>(Node(data));
    if (tail == nullptr) {
      tail = newPtr;
      head = newPtr;
    } else {
      tail->next = newPtr;
      tail = newPtr;
      // std::cout << "q";
    }
    length++;
  }

  std::shared_ptr<Node> deleteNext(std::shared_ptr<Node> delNode) {
    if (delNode->next->next == nullptr) {
      delNode->next = nullptr;
      tail = delNode;
    } else {
      delNode->next = delNode->next->next;
    }
    length--;
    return delNode->next;
  }

  std::shared_ptr<Node> deleteThis(std::shared_ptr<Node> delNode) {
    if (delNode == head) {
      head = head->next;
      return head;
    } else {
      std::shared_ptr<Node> temp(head);
      if (delNode->next == nullptr) {
        while (temp->next != delNode) {
          temp = temp->next;
        }
        tail = temp;
        temp->next = nullptr;
      } else {
        while (temp->next != delNode) {
          temp = temp->next;
        }
        temp->next = delNode->next;
      }
      length--;
      return temp->next;
    }
  }

  void printList() {
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