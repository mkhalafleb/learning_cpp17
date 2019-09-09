#include <iostream>
#include <memory>
#include "node.h"
#include "graph.h"

int main () { 
  graph::Graph graph;
  graphnode::Node node_a(0), node_b(2);

  std::cout << "Node A: " << node_a << std::endl;
  std::cout << "Node B: " << node_b << std::endl;

  std::weak_ptr<graphnode::Node> nodeptr = graph.AddNode();
  if (auto spt = nodeptr.lock()) {
    std::cout << "Node C: " << *spt << std::endl;
  }
  else { 
    exit (1);
  }
}

