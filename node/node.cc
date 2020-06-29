#include "node.h"
#include "nodeid/nodeid.h"
#include <assert.h>
#include <iostream>
#include <limits>
#include <memory>
#include <optional>
#include <utility>

namespace graphnode {

// Return a struct that has both the current NodeId and the original one at the
// creation of the Node
Node::DualId Node::GetIds() const { return (Node::DualId{id_, original_id_}); }

void Node::AddNeighbour(std::weak_ptr<Node> neighbour) {
  assert(!next_.has_value());
  next_ = neighbour;
};

bool Node::HasNeighbour() const { return (next_.has_value()); };

// if it has a neighbour return it otherwise assert because it should not
// be called. I thought I also maybe should return an empty weak_ptr but for
// now assert
std::weak_ptr<Node> Node::GetNeighbour() const {
  assert(this->HasNeighbour());
  // It also should not be expired
  assert(!next_->expired());
  return (*next_);
};

std::ostream &operator<<(std::ostream &os, const Node &node) {
  os << node.id_;
  return (os);
}

Node::Node(const Node::DualId &dual_id)
    : id_(dual_id.nodeid_), original_id_(dual_id.original_id_),
      next_(std::nullopt){};

} // namespace graphnode
