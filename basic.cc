#include <iostream>
#include "node.h"

int main () {
  graph_node::Node node(0);
  std::cout << "Hello World ID: " << node.GetId() <<  std::endl;
}

