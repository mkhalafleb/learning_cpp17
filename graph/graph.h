#ifndef MKHALAF_LEARNINGCPP17_GRAPH
#define MKHALAF_LEARNINGCPP17_GRAPH
#include "node/node.h"
#include <list>
#include <memory>
#include <optional>
#include <utility>
#include <vector>

namespace graph {

class Graph {
public:
  // The owner of the node is the graph so everyone else deals with weak ptrs
  // to the node so if I create a node, I get a weak ptr back of the node
  std::weak_ptr<graphnode::Node> AddNode(const nodeid::NodeId &node_id);

  // This graph currently only supports one edge out of each node maximum
  // This is only for debugging
  std::vector<std::pair<unsigned int, std::optional<unsigned int>>>
  GetAdjList() const;

  // Get a list of weak pointer to all the graph nodes
  // The list is sorted by the original creation NodeId of the node
  // This sorting is really to stabilize some debugging
  // It should not be used for anything really and is not necessarily
  // a property of the graph
  const std::list<std::weak_ptr<graphnode::Node>> GetNodeList() const;

private:
  void
  FillAdjPair(const graphnode::Node &node,
              std::vector<std::pair<unsigned int, std::optional<unsigned int>>>
                  &adjlist) const;

  static bool CompareNodePtr(const std::weak_ptr<graphnode::Node> &node_a,
                             const std::weak_ptr<graphnode::Node> &node_b);

  static unsigned int lastnodeid_;
  std::list<std::shared_ptr<graphnode::Node>> nodelist_;
};

} // namespace graph

#endif // MKHALAF_LEARNINGCPP17_GRAPH
