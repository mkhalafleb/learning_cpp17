#include "node.h"


namespace graph_node {

Node::Node(unsigned int id): id(id) {};

unsigned int Node::GetId() const  {
  return(id);
};

} // namespace graph_node







