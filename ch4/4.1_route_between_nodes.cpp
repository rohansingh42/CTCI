#include "Graph.hpp"

int main() {
  int n, s, g;
  std::cout << "Enter number of nodes : ";
  std::cin >> n;
  // int **adjMat;
  // adjMat = new int *[n];
  // for(int i = 0; i < n; i++) {
  //   adjMat[i] = new int[n];
  // }
  std::cout << "Enter start node index : ";
  std::cin >> s;
  std::cout << "Enter goal node index : ";
  std::cin >> g;
  Graph graph = Graph(n, 0.01);
  // graph.printAdjList();

  std::cout << "Checking for route...." << std::endl;

  std::cout << "A route " <<
    (graph.checkRoute(s,g) ? "exists." : "does not exist.");
  std::cout << std::endl;
  return 0;
}