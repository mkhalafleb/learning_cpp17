#include <iostream>
#include "nodeid.h"


namespace nodeid {

NodeId::NodeId(int id): id_(id) {};


bool NodeId::operator==(const NodeId &nodeid) {
  bool bothvalid = IsValid() && nodeid.IsValid();
  return (bothvalid && (id_ ==  nodeid.id_));
}

bool NodeId::operator!=(const NodeId &nodeid) {
  return(!((*this) == nodeid));
}

std::ostream& operator<<(std::ostream &os, const NodeId &nodeid) {
  os << nodeid.id_;
  return(os);
}

// A nodeID is valid only if it is assigned a positive number or 0
bool NodeId::IsValid() const {
  // Need to handle Overflow somehow.
  return (id_ >= 0);
};

} // namespace nodeid







