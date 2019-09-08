#ifndef MKHALAF_LEARNINGCPP17_NODE
#define MKHALAF_LEARNINGCPP17_NODE
#include <iostream>
#include "nodeid.h"

namespace graphnode {
    

class Node {
 public:
  Node(int id);
	
  friend std::ostream& operator<<(std::ostream &os, const Node &node);

 private:
  nodeid::NodeId id_;
};

} // namespace graphnode


#endif  // MKHALAF_LEARNINGCPP17_NODE



