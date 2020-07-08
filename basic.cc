#include "algorithm/algorithm.h"
#include "graph/graph.h"
#include "graphcreator/graphcreator.h"
#include "node/node.h"
#include <cassert>
#include <filesystem>
#include <iostream>
#include <list>
#include <memory>
#include <optional>
#include <string>

std::string FullPath(const std::string &endpath) {
  std::filesystem::path basepath = std::filesystem::current_path();
  basepath /= std::filesystem::path(endpath);
  return (basepath.string());
};

int main() {
  graph::Graph graph;
  graphnode::Node node_a({0, 1}), node_b({2, 2});

  std::cout << "Node A: " << node_a << std::endl;
  std::cout << "Node B: " << node_b << std::endl;

  std::weak_ptr<graphnode::Node> nodeptr = graph.AddNode(0);
  if (auto spt = nodeptr.lock()) {
    std::cout << "Node C: " << *spt << std::endl;
  } else {
    exit(1);
  }
  nodeptr = graph.AddNode(0);
  if (auto spt = nodeptr.lock()) {
    std::cout << "Node D: " << *spt << std::endl;
  } else {
    exit(1);
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

  // Print the nodes
  const std::list<std::weak_ptr<graphnode::Node>> node_list =
      graph2->GetNodeList();
  std::cout << "Node List" << std::endl;
  for (auto node : node_list) {
    assert(!node.expired());
    std::cout << (node.lock())->GetIds().original_id_ << ", ";
  }
  std::cout << std::endl;
  std::cout << "Edge List" << std::endl;
  for (auto node : node_list) {
    assert(!node.expired());
    auto sp = node.lock();
    std::cout << sp->GetIds().original_id_ << "-> ";
    if (sp->HasNeighbour()) {
      auto nlist = sp->GetNeighbours();
      assert(nlist.size() == 1);
      auto neighbour = nlist.front();
      assert(!neighbour.expired());
      auto sp_n = neighbour.lock();
      std::cout << sp_n->GetIds().original_id_;
      std::cout << std::endl;
    } else {
      std::cout << std::endl;
    }
  }
  std::cout << std::endl;

  std::string path = algorithm::GraphDFS(*graph2);
  std::cout << "PATH = " << path << std::endl;
}
