#include "algorithm.h"
#include "graph/graph.h"
#include "node/node.h"
#include "nodeid/nodeid.h"
#include <algorithm>
#include <memory>
#include <string>

namespace algorithm {

void GraphNodeClear(const graph::Graph &bgraph) {

  auto nodelist = bgraph.GetNodeList();
  std::for_each(nodelist.begin(), nodelist.end(),
                [](std::weak_ptr<graphnode::Node> &node) {
                  if (auto sp = node.lock()) {
                    sp->SetLabel(-1);
                  }
                });
}

std::string GraphDFSVisit(std::weak_ptr<graphnode::Node> node_ptr) {
  // -1 is never visited
  // 0 is first time I see it
  // 1 is done with all its children
  std::string visit_path("");
  auto sp = node_ptr.lock();
  if (!sp) {
    return ("");
  }

  if (sp->GetLabel() == -1) {
    // First Time we have seen the node so add it to the string
    visit_path +=
        std::to_string((sp->GetIds().original_id_).GetDebugId()) + ",";
    sp->SetLabel(0);
    // if Leaf node
    if (!sp->HasNeighbour()) {
      sp->SetLabel(1);
      return (visit_path);
    }
    visit_path += GraphDFSVisit(sp->GetNeighbour());
    sp->SetLabel(1);
  }
  return (visit_path);
} // namespace algorithm

std::string GraphDFS(const graph::Graph &bgraph) {
  std::string visit_path("");
  GraphNodeClear(bgraph);
  auto nodelist = bgraph.GetNodeList();
  std::for_each(nodelist.begin(), nodelist.end(),
                [&visit_path](std::weak_ptr<graphnode::Node> &node_ptr) {
                  if (auto sp = node_ptr.lock()) {
                    visit_path += GraphDFSVisit(node_ptr);
                  }
                });
  return (visit_path);
}

} // namespace algorithm
