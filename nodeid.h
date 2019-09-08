#ifndef MKHALAF_LEARNINGCPP17_NODEID
#define MKHALAF_LEARNINGCPP17_NODEID

namespace nodeid {

class NodeId {
 public:

  NodeId(int nodeid);
  bool operator== (const NodeId &nodeid);
  bool operator!= (const NodeId &nodeid);
  // a Node can have an invalid ID and can only be compared if it is really
  // valid
  bool IsValid() const;

  friend std::ostream& operator<<(std::ostream &os, const NodeId &nodeid);

 private:
  int id_;
};

} // namespace nodeid


#endif  // MKHALAF_LEARNINGCPP17_NODEID



