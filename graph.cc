#include "graph.h"
#include "node.h"


namespace graph {

unsigned int Graph::lastnodeid_ = 0;


std::weak_ptr<graphnode::Node> Graph::AddNode() {
  // Nodes should have unique IDs but for now this is a dummy function
  // that just adds a dummy node and adds it to the list
  nodelist_.emplace_front(std::make_shared<graphnode::Node> (lastnodeid_++));
  return(nodelist_.front());
}




} // namespace graphnode







