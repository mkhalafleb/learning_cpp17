#include "graphcreator.h"
#include "graph.h"
#include "node/node.h"
#include "textreader/textreader.h"
#include "fixadjacency/fixadjacency.h"
#include <string>
#include <optional>


namespace graphcreator {

GraphCreator::GraphCreator(const std::string &filename) : filename_(filename) {};


bool GraphCreator::GetEdgeList() {

  textreader::TextReader textparser(filename_);
  if (!textparser.CreateAdjacency()) {
    return(false);
  }
  auto adjvec = textparser.GetAdjacency();

  fixadjacency::FixAdjacency adjfix(adjvec);

  if (!adjfix.VerifyAdjacency()) {
    return(false);
  }

  if (!adjfix.RepairAdjacency()) {
    return(false);
  }

  adjlist_ = adjfix.GetAdjacency();
  return(true);

}

// Create Graph from the file that is passed on to the class and saved in
// filename_
//
void GraphCreator::PopulateGraph() {

  // Iterate over the list and for each edge, if not in map, create the Node,
  // insert it into Map, check the destination, if not in map, create the dest
  // node and set it as weak_ptr
}

// Return nullopt if the graph can't be created
std::optional<graph::Graph> GraphCreator::CreateGraph() {

  // Read the file 
  if (!GetEdgeList()) {
    return(std::nullopt);
  }

  PopulateGraph();

  return(std::make_optional(graph_));
}





} // namespace graphcreator







