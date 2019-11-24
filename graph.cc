#include "graph.h"
#include "node/node.h"
#include <string>
#include <functional>
#include <algorithm>


namespace graph {

unsigned int Graph::lastnodeid_ = 0;


void Graph::FillAdjPair(const graphnode::Node &node,
                        std::vector<std::pair<unsigned int, std::optional<unsigned int>>> &adjlist) const {
  unsigned int creation_id = (node.GetId()).second;

  if (!node.HasNeighbour()) {
    adjlist.push_back(std::make_pair(creation_id, std::nullopt));
  }
  else {
    auto sp = node.GetNeighbour().lock(); 
    adjlist.push_back(std::make_pair(creation_id, std::make_optional((sp->GetId()).second)));
  }
}



std::vector<std::pair<unsigned int,
    std::optional<unsigned int>>> Graph::GetAdjList() const {
  std::vector<std::pair<unsigned int, std::optional<unsigned int>>> adjlist;

  // Capture into a lambda
  auto fill_list = [&adjlist, this] (std::shared_ptr<graphnode::Node> node_ptr) {
    this->FillAdjPair(*node_ptr, adjlist);
  };

  // For each node, we need to 
  std::for_each(nodelist_.begin(), nodelist_.end(), fill_list);

  return(adjlist);
}

std::weak_ptr<graphnode::Node> Graph::AddNode(unsigned int node_id) {
  // Nodes should have unique IDs but for now this is a dummy function
  // that just adds a dummy node and adds it to the list
  nodelist_.emplace_front(std::make_shared<graphnode::Node> (lastnodeid_++, node_id));
  return(nodelist_.front());
}




} // namespace graphnode







