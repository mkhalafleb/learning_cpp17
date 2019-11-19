#include "graphcreator.h"
#include "graph.h"
#include "node/node.h"
#include "textreader/textreader.h"
#include "fixadjacency/fixadjacency.h"
#include <string>
#include <optional>
#include <unordered_map>
#include <list>


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

  // Iterate over the list and for each edge, if not in map, create the graphnode::Node,
  // insert it into Map, check the destination, if not in map, create the dest
  // node and set it as weak_ptr
  for (auto listiter = adjlist_.begin();
       listiter != adjlist_.end();
       ++listiter)  {
    std::pair<unsigned int, std::optional<unsigned int>> edge = *listiter;

    // Is node present
    auto it = nodemap_.find(edge.first);
    std::weak_ptr<graphnode::Node> source_node;
    if (it == nodemap_.end()) {
      // New Node
      source_node = graph_.AddNode();
      nodemap_.emplace(std::make_pair(edge.first, source_node));
      if (auto sp = source_node.lock()) {
        sp->SetOriginalId(edge.first);
      }
      else {
          // Error!
      }
    }
    else {
      source_node = (*it).second;
    }
    // Has a destination
    if (edge.second.has_value()) {
      std::weak_ptr<graphnode::Node> dest_node; 
      it = nodemap_.find(*(edge.second));
      if (it == nodemap_.end()) {
        // create the node and link it
        dest_node = graph_.AddNode(); 
        if (auto sp = dest_node.lock()) {
          sp->SetOriginalId(*edge.second);
        }
        else {
          // Error
        }
        nodemap_.emplace(std::make_pair(edge.first, dest_node));
        if (auto sp = source_node.lock()) {
          sp->AddNeighbour(dest_node);
        }
        else {
          // Error!
        }
      }
      else {
        dest_node = (*it).second;
        if (auto sp = source_node.lock()) {
          sp->AddNeighbour(dest_node);
        }
        else {
          // Error!
        }
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







