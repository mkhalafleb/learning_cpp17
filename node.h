#ifndef MKHALAF_LEARNINGCPP17_NODE
#define MKHALAF_LEARNINGCPP17_NODE
#include "nodeid.h"

namespace graphnode {

class Node {
 public:
  Node(int id);

  // TODO(How do I print NodeId. Need to print it).

 private:
  nodeid::NodeId id_;
};

} // namespace graphnode


#endif  // MKHALAF_LEARNINGCPP17_NODE



