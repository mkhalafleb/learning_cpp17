#include "graph.h"
#include "node/node.h"
#include <algorithm>
#include <functional>
#include <string>

namespace graph {

unsigned int Graph::lastnodeid_ = 0;

void Graph::FillAdjPair(
    const graphnode::Node &node,
    std::vector<std::pair<unsigned int, std::optional<unsigned int>>> &adjlist)
    const {

  unsigned int creation_id = (node.GetIds().original_id_).GetDebugId();

  if (!node.HasNeighbour()) {
    adjlist.push_back(std::make_pair(creation_id, std::nullopt));
  } else {
    auto nlist = node.GetNeighbours();
    // For now, we support only 1 edge out of node
    auto sp = nlist.back().lock();
    adjlist.push_back(std::make_pair(
        creation_id,
        std::make_optional((sp->GetIds().original_id_).GetDebugId())));
  }
}

std::vector<std::pair<unsigned int, std::optional<unsigned int>>>
Graph::GetAdjList() const {
  std::vector<std::pair<unsigned int, std::optional<unsigned int>>> adjlist;

  // Capture into a lambda
  auto fill_list = [&adjlist, this](std::shared_ptr<graphnode::Node> node_ptr) {
    this->FillAdjPair(*node_ptr, adjlist);
  };

  // For each node, we need to
  std::for_each(nodelist_.begin(), nodelist_.end(), fill_list);

  return (adjlist);
}

std::weak_ptr<graphnode::Node> Graph::AddNode(const nodeid::NodeId &node_id) {
  // Nodes should have unique IDs but for now this is a dummy function
  // that just adds a dummy node and adds it to the list
  nodelist_.emplace_front(std::make_shared<graphnode::Node>(
      graphnode::Node::DualId{lastnodeid_++, node_id}));
  return (nodelist_.front());
}

bool Graph::CompareNodePtr(const std::weak_ptr<graphnode::Node> &node_a,
                           const std::weak_ptr<graphnode::Node> &node_b) {
  if (node_a.expired() || node_b.expired()) {
    return (true);
  }

  graphnode::Node node_a_full = *(node_a.lock());
  graphnode::Node node_b_full = *(node_b.lock());

  return (node_a_full.GetIds().original_id_ <
          node_b_full.GetIds().original_id_);
}

const std::list<std::weak_ptr<graphnode::Node>> Graph::GetNodeList() const {
  std::list<std::weak_ptr<graphnode::Node>> list_node_ptr;
  auto fill_list = [&list_node_ptr](std::shared_ptr<graphnode::Node> node_ptr) {
    list_node_ptr.emplace_front(node_ptr);
  };

  std::for_each(nodelist_.begin(), nodelist_.end(), fill_list);
  list_node_ptr.sort(CompareNodePtr);
  return (list_node_ptr);
}

} // namespace graph
