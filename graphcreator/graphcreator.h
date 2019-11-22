#ifndef MKHALAF_LEARNINGCPP17_GRAPHCREATOR
#define MKHALAF_LEARNINGCPP17_GRAPHCREATOR
#include "graph.h"
#include "node/node.h"
#include <string>
#include <optional>
#include <utility>
#include <list>
#include <memory>
#include <unordered_map>

namespace graphcreator {

class GraphCreator {
 public:
  // This is an absolute path for a file
  GraphCreator(const std::string &filename);


  // We are using optional here in a way that if it is not returned
  // then we failed in GraphCreation
  std::optional<graph::Graph> CreateGraph();

 private:
  // Fill the adjlist_ by reading the filename_
  bool GetEdgeList();

  std::weak_ptr<graphnode::Node> GetNodePtr(unsigned int node_id);

  // Fill the graph class
  void PopulateGraph();
  graph::Graph graph_;
  std::string filename_;

  // Temp processing adjacency list
  std::list<std::pair<unsigned int, std::optional<unsigned int>>> adjlist_;

  // Temp processing of Graph Nodes
  std::unordered_map<unsigned int, std::weak_ptr<graphnode::Node>> nodemap_;

};

} // namespace graphcreator


#endif  // MKHALAF_LEARNINGCPP17_GRAPHCREATOR
