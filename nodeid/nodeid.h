#ifndef MKHALAF_LEARNINGCPP17_NODEID
#define MKHALAF_LEARNINGCPP17_NODEID
#include <iostream>

namespace nodeid {

class NodeId {
public:
  NodeId(unsigned int nodeid);
  bool operator==(const NodeId &nodeid) const;
  bool operator!=(const NodeId &nodeid) const;
  bool operator<(const NodeId &nodeid) const;
  bool operator>(const NodeId &nodeid) const;
  // a Node can have an invalid ID and can only be compared if it is really
  // valid
  bool IsValid() const;

  // Only for debugging
  unsigned int GetDebugId() const;

  friend std::ostream &operator<<(std::ostream &os, const NodeId &nodeid);

private:
  int id_;
};

} // namespace nodeid

#endif // MKHALAF_LEARNINGCPP17_NODEID
