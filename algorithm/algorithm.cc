#include "algorithm.h"
#include "graph/graph.h"
#include "node/node.h"
#include "nodeid/nodeid.h"
#include <algorithm>
#include <memory>
#include <queue>
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

std::string
GraphBFSVisit(std::queue<std::weak_ptr<graphnode::Node>> &bfs_queue) {
  // -1 is never visited
  // 0 is first time I see it
  // 1 is done with all its children
  std::string visit_path("");

  auto sp = bfs_queue.front().lock();
  if (!sp) {
    return ("");
  }

  // Pop the queue because we are not processing sp
  bfs_queue.pop();

  // Now the node is either -1 which is never visited
  // 0, I have seen it before
  // 1, I have done all its childen
  if (sp->GetLabel() == -1) {
    // Enqueue all the children
    sp->SetLabel(0);
    // Does it have neighbours
    if (sp->HasNeighbour()) {
      auto node_neighbours = sp->GetNeighbours();
      for (auto node : node_neighbours) {
        auto sp = node.lock();
        if ((sp) && (sp->GetLabel() == -1)) {
          sp->SetLabel(0);
          bfs_queue.push(node);
        }
      }
    }
  }
  visit_path += std::to_string((sp->GetIds().original_id_).GetDebugId()) + ",";
  sp->SetLabel(1);
  visit_path += GraphBFSVisit(bfs_queue);

  return (visit_path);
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
    sp->SetLabel(0);
    // if Leaf node
    if (!sp->HasNeighbour()) {
      visit_path +=
          std::to_string((sp->GetIds().original_id_).GetDebugId()) + ",";
      sp->SetLabel(1);
      return (visit_path);
    }
    for (auto node : sp->GetNeighbours()) {
      visit_path += GraphDFSVisit(node);
    }
    // First Time we have seen the node so add it to the string
    visit_path +=
        std::to_string((sp->GetIds().original_id_).GetDebugId()) + ",";
    sp->SetLabel(1);
  }
  return (visit_path);
}

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

std::string GraphBFS(const graph::Graph &bgraph) {
  std::string visit_path("");
  std::queue<std::weak_ptr<graphnode::Node>> bfs_queue;
  GraphNodeClear(bgraph);
  auto nodelist = bgraph.GetNodeList();
  std::for_each(
      nodelist.begin(), nodelist.end(),
      [&visit_path, &bfs_queue](std::weak_ptr<graphnode::Node> &node_ptr) {
        auto sp = node_ptr.lock();
        if (sp && (sp->GetLabel() == -1)) {
          bfs_queue.push(node_ptr);
          visit_path += GraphBFSVisit(bfs_queue);
        }
      });
  return (visit_path);
}

} // namespace algorithm
