#ifndef MKHALAF_LEARNINGCPP17_GRAPH
#define MKHALAF_LEARNINGCPP17_GRAPH
#include <list>
#include <memory>
#include <vector>
#include <optional>
#include <utility>
#include "node/node.h"

namespace graph {

class Graph {
 public:
  // The owner of the node is the graph so everyone else deals with weak ptrs
  // to the node so if I create a node, I get a weak ptr back of the node
  std::weak_ptr<graphnode::Node> AddNode(unsigned int node_id);

  // This graph currently only supports one edge out of each node maximum
  // This is only for debugging
  std::vector<std::pair<unsigned int, std::optional<unsigned int>>> GetAdjList() const;

  // Get a list of weak pointer to all the graph nodes
  const std::list<std::weak_ptr<graphnode::Node>> GetNodeList() const; 

 private:

  void FillAdjPair(const graphnode::Node &node,
       std::vector<std::pair<unsigned int, std::optional<unsigned int>>> &adjlist) const;
  static unsigned int lastnodeid_;
  std::list<std::shared_ptr<graphnode::Node>> nodelist_;
};

} // namespace graph


#endif  // MKHALAF_LEARNINGCPP17_GRAPH



