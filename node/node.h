#ifndef MKHALAF_LEARNINGCPP17_NODE
#define MKHALAF_LEARNINGCPP17_NODE
#include <iostream>
#include <optional>
#include <memory>
#include <utility>
#include "nodeid/nodeid.h"

namespace graphnode {

class Node {
 public:

  struct DualId {
    nodeid::NodeId nodeid_;
    nodeid::NodeId original_id_;
  };

  Node(const Node::DualId &dual_id);

  void AddNeighbour(std::weak_ptr<Node> neighbour);

  bool HasNeighbour() const;

  std::weak_ptr<Node> GetNeighbour() const;

  Node::DualId GetIds() const;

  friend std::ostream& operator<<(std::ostream &os, const Node &node);

 private:
  int label; // Used as a label for node
  nodeid::NodeId id_;
  nodeid::NodeId original_id_; // only used as a marker during creation

  // Each node has one and only one next pointer for now and does
  // not own the next node.
  // If there is no pointer, then the node is a leaf node
  std::optional <std::weak_ptr<Node>> next_;
};

} // namespace graphnode


#endif  // MKHALAF_LEARNINGCPP17_NODE



