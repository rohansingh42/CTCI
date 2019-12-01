#pragma once

#include <algorithm>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <random>
#include <queue>

#include "Node.hpp"

class Graph {
  int dim;
  std::vector<std::vector<int>> adjMat;

 public:
  Graph () : dim(0) {}

  Graph (int n, float p = 0.5) {
    dim = n;
    adjMat = std::vector<std::vector<int>>
                 (n, std::vector<int> (n, 0));

    auto dist = std::bernoulli_distribution(p);
    auto gen = std::default_random_engine();
    for (int i = 0; i < dim; i++) {
      for (int j = 0; j < dim; j++) {
        if (i != j) {
          adjMat[i][j] = static_cast<int>(dist(gen));
        }
      }
    }
  }

  void printAdjList () {
    for (int i = 0; i < dim; i++) {
      std::cout << i << " : ";
      for (int j = 0; j < dim; j++) {
        if (adjMat[i][j] == 1) {
          std::cout << j << " ";
        }
      }
      std::cout << std::endl;
    }
  }

  std::vector<std::vector<int>> getAdjMat () {
    return adjMat;
  }

  int getDim () {
    return dim;
  }

  bool checkRoute (int s, int g) {
    if (s >= dim || g >= dim) {
      return false;
    }
    if (s == g) {
      return true;
    }
    std::queue<int> open;
    std::unordered_set<int> visited;
    visited.insert(s);
    open.push(s);
    int curr = s;
    while (open.empty() == false) {
      curr = open.front();
      open.pop();
      for (int i = 0; i < dim; i++) {
        if (adjMat[curr][i] == 1) {
          if (i == g) {
            return true;
          }
          if (visited.count(i) == 0) {
            open.push(i);
            visited.insert(i);
          }
        }
      }
    }
    return false;
  }
};