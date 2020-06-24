#include <iostream>
#include <limits>

#include "nodeid.h"



namespace nodeid {

NodeId::NodeId(unsigned int nodeid) {
  // id_ is an int because we want to use negative values as illegal
  if (nodeid > static_cast<unsigned int> (std::numeric_limits<int>::max())) {
    id_ = -1;
  } else {
    id_ = nodeid;
  }
};


bool NodeId::operator==(const NodeId &nodeid) const {
  bool bothvalid = IsValid() && nodeid.IsValid();
  return (bothvalid && (id_ ==  nodeid.id_));
}

bool NodeId::operator!=(const NodeId &nodeid) const {
  return(!((*this) == nodeid));
}

unsigned int NodeId::GetDebugId() const {
  return(id_);
}

std::ostream& operator<<(std::ostream &os, const NodeId &nodeid) {
  os << nodeid.id_;
  return(os);
}

// A nodeID is valid only if it is assigned a positive number or 0
bool NodeId::IsValid() const {
  return (id_ >= 0);
};

} // namespace nodeid







