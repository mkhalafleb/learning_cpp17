#ifndef MKHALAF_LEARNINGCPP17_GRAPHCREATOR
#define MKHALAF_LEARNINGCPP17_GRAPHCREATOR
#include "graph.h"
#include <string>
#include <optional>

namespace graphcreator {

class GraphCreator {
 public:
  // This is an absolute path for a file
  GraphCreator(const std::string &filename);

  // We are using optional here in a way that if it is not returned
  // then we failed in GraphCreation
  std::optional<graph::Graph> CreateGraph();

 private:
  std::string filename_;
};

} // namespace graphcreator


#endif  // MKHALAF_LEARNINGCPP17_GRAPHCREATOR
