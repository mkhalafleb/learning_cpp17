#include "graphcreator.h"
#include "graph.h"
#include <string>
#include <optional>


namespace graphcreator {

GraphCreator::GraphCreator(const std::string &filename) : filename_(filename) {};



// Create Graph from the file that is passed on to the class and saved in
// filename_

// Return nullopt if the graph can't be created
std::optional<graph::Graph> GraphCreator::CreateGraph() {
  return(std::nullopt);
}





} // namespace graphcreator







