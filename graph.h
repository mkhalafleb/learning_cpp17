#ifndef MKHALAF_LEARNINGCPP17_GRAPH
#define MKHALAF_LEARNINGCPP17_GRAPH
#include <list>
#include <memory>
#include "node/node.h"

namespace graph {

class Graph {
 public:
  // The owner of the node is the graph so everyone else deals with weak ptrs
  // to the node so if I create a node, I get a weak ptr back of the node
  std::weak_ptr<graphnode::Node> AddNode();

 private:
  static unsigned int lastnodeid_;
  std::list<std::shared_ptr<graphnode::Node>> nodelist_;
};

} // namespace graph


#endif  // MKHALAF_LEARNINGCPP17_GRAPH



