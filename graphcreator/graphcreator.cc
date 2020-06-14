#include "graphcreator.h"
#include "graph/graph.h"
#include "node/node.h"
#include "textreader/textreader.h"
#include "fixadjacency/fixadjacency.h"
#include <string>
#include <optional>
#include <unordered_map>
#include <list>
#include <cassert>


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

std::weak_ptr<graphnode::Node> GraphCreator::GetNodePtr(unsigned int node_id) {
  std::weak_ptr<graphnode::Node> node_ptr;
  auto it = nodemap_.find(node_id);
  if (it == nodemap_.end()) {
      node_ptr = graph_.AddNode(node_id);
      nodemap_.insert(std::make_pair(node_id, node_ptr));
      return(node_ptr);
  }
  else {
    node_ptr = (*it).second;
    return(node_ptr);
  }
}




// Create Graph from the file that is passed on to the class and saved in
// filename_
//
void GraphCreator::PopulateGraph() {

  // Iterate over the list and for each edge, if not in map, create the graphnode::Node,
  // insert it into Map, check the destination, if not in map, create the dest
  // node and set it as weak_ptr
  for (auto listiter = adjlist_.begin();
       listiter != adjlist_.end();
       ++listiter)  {
    std::pair<unsigned int, std::optional<unsigned int>> edge = *listiter;

    // Is node present
    std::weak_ptr<graphnode::Node> source_node = GetNodePtr(edge.first);
    assert(!source_node.expired());
    // Has a destination
    if (edge.second.has_value()) {
      std::weak_ptr<graphnode::Node> dest_node = GetNodePtr(*(edge.second)); 
      assert(!dest_node.expired());
      if (auto sp = source_node.lock()) {
         sp->AddNeighbour(dest_node);
      }
    }
  }
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







