#include <iostream>
#include <memory>
#include "node/node.h"
#include "graph.h"

int main () {
  graph::Graph graph;
  graphnode::Node node_a(0, 1), node_b(2, 2);

  std::cout << "Node A: " << node_a << std::endl;
  std::cout << "Node B: " << node_b << std::endl;

  std::weak_ptr<graphnode::Node> nodeptr = graph.AddNode(0);
  if (auto spt = nodeptr.lock()) {
    std::cout << "Node C: " << *spt << std::endl;
  }
  else {
    exit (1);
  }
  nodeptr = graph.AddNode(0);
  if (auto spt = nodeptr.lock()) {
    std::cout << "Node D: " << *spt << std::endl;
  }
  else {
    exit (1);
  }
}

