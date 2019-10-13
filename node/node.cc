#include <iostream>
#include <memory>
#include <assert.h>
#include <optional>
#include "node.h"
#include "nodeid/nodeid.h"


namespace graphnode {

void Node::AddNeighbour(std::weak_ptr<Node> neighbour) {
  assert(!next_.has_value());
  next_ = neighbour;
};

bool Node::HasNeighbour() const {
  return(next_.has_value());
};

// if it has a neighbour return it otherwise assert because it should not
// be called. I thought I also maybe should return an empty weak_ptr but for
// now assert
std::weak_ptr<Node> Node::GetNeighbour() const {
  assert(this->HasNeighbour());
  // It also should not be expired
  assert(!next_->expired());
  return(*next_);
};

std::ostream& operator<<(std::ostream &os, const Node &node) {
  os << node.id_;
  return(os);
}



Node::Node (const nodeid::NodeId &nodeid): id_(nodeid), next_(std::nullopt) {};


} // namespace graphnode







