#include <iostream>
#include <memory>
#include <optional>
#include <filesystem>
#include <string>
#include <cassert>
#include "node/node.h"
#include "graph/graph.h"
#include "graphcreator/graphcreator.h"


std::string FullPath(const std::string &endpath) {
  std::filesystem::path basepath = std::filesystem::current_path();
  basepath /= std::filesystem::path(endpath);
  return(basepath.string());
};

int main () {
  graph::Graph graph;
  graphnode::Node node_a(graphnode::Node::DualId{0, 1}), node_b(graphnode::Node::DualId{2, 2});

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


  // Do Graph2 test
  graphcreator::GraphCreator creator(FullPath("basic_graph"));
  std::optional<graph::Graph> graph2 = creator.CreateGraph();
  assert(graph2.has_value());
  auto adjlist = graph2->GetAdjList();
  for (auto edge : adjlist) {
    std::cout << edge.first << ",";
    if (edge.second.has_value()) {
      std::cout << *(edge.second);
    }
    std::cout << std::endl;

  }

}

