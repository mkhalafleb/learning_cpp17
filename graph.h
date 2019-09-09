#ifndef MKHALAF_LEARNINGCPP17_GRAPH
#define MKHALAF_LEARNINGCPP17_GRAPH
#include <list>
#include <memory>
#include "graph.h"
#include "node.h"

namespace graph {
    

class Graph {
 public:	
  
  // The owner of the node is the graph so everyone else deals with weak ptrs
  // to the node so if I create a node, I get a weak ptr back of the node
  std::weak_ptr<graphnode::Node> AddNode();  

 private:
  std::list<std::shared_ptr<graphnode::Node>> nodelist;
};

} // namespace graph


#endif  // MKHALAF_LEARNINGCPP17_GRAPH



