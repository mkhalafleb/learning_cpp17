#include "graph.h"
#include "node.h"


namespace graph {


std::weak_ptr<graphnode::Node> Graph::AddNode() {
  // Nodes should have unique IDs but for now this is a dummy function
  // that just adds a dummy node and adds it to the list
  nodelist.emplace_front(std::make_shared<graphnode::Node> (1));
  return(nodelist.front());
}




} // namespace graphnode







