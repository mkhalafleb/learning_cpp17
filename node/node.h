#ifndef MKHALAF_LEARNINGCPP17_NODE
#define MKHALAF_LEARNINGCPP17_NODE
#include <iostream>
#include <optional>
#include <memory>
#include "nodeid/nodeid.h"

namespace graphnode {

class Node {
 public:
  Node(const nodeid::NodeId &nodeid);

  void AddNeighbour(std::weak_ptr<Node> neighbour);

  bool HasNeighbour() const;

  std::weak_ptr<Node> GetNeighbour() const;

  friend std::ostream& operator<<(std::ostream &os, const Node &node);

 private:
  nodeid::NodeId id_;
  std::optional <std::weak_ptr<Node>> next_;
  // Each node has one and only one next pointer for now and does
  // not own the next node.
};

} // namespace graphnode


#endif  // MKHALAF_LEARNINGCPP17_NODE



