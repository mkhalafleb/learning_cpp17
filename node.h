#ifndef MKHALAF_LEARNINGCPP17_NODE
#define MKHALAF_LEARNINGCPP17_NODE

namespace graph_node {

class Node {
 public:
  Node(unsigned int);

  unsigned int GetId() const;

 private:
  unsigned int id;
};

} // namespace graph_node


#endif  // MKHALAF_LEARNINGCPP17_NODE



