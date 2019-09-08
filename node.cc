#include <iostream>
#include "node.h"
#include "nodeid.h"


namespace graphnode {


std::ostream& operator<<(std::ostream &os, const Node &node) {
  os << node.id_;
  return(os);
}



Node::Node (int id): id_(nodeid::NodeId(id)) {};


} // namespace graphnode







