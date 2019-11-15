#ifndef MKHALAF_LEARNINGCPP17_GRAPHCREATOR
#define MKHALAF_LEARNINGCPP17_GRAPHCREATOR
#include "graph.h"
#include <string>
#include <optional>
#include <utility>
#include <list>

namespace graphcreator {

class GraphCreator {
 public:
  // This is an absolute path for a file
  GraphCreator(const std::string &filename);

  // Fill the adjlist_ by reading the filename_
  bool GetEdgeList();

  // We are using optional here in a way that if it is not returned
  // then we failed in GraphCreation
  std::optional<graph::Graph> CreateGraph();

 private:
  std::string filename_;
  std::list<std::pair<unsigned int, std::optional<unsigned int>>> adjlist_;
};

} // namespace graphcreator


#endif  // MKHALAF_LEARNINGCPP17_GRAPHCREATOR
