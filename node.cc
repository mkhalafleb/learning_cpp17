#include <iostream>
#include <memory>
#include <assert.h>
#include "node.h"
#include "nodeid.h"


namespace graphnode {

void Node::AddNeighbour(std::weak_ptr<Node> neighbour) {
  assert(next_.expired());
  next_ = neighbour;
};

std::weak_ptr<Node> Node::GetNeighbour() const {
  return(next_);
};

std::ostream& operator<<(std::ostream &os, const Node &node) {
  os << node.id_;
  return(os);
}



Node::Node (const nodeid::NodeId &nodeid): id_(nodeid), next_(std::weak_ptr<Node>()) {};


} // namespace graphnode







