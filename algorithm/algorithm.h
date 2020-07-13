#ifndef MKHALAF_LEARNINGCPP17_ALGORITHM
#define MKHALAF_LEARNINGCPP17_ALGORITHM
#include "graph/graph.h"
#include "node/node.h"
#include "nodeid/nodeid.h"
#include <memory>
#include <queue>

namespace algorithm {

// Traverses the graph in a DFS manner and builds a comma separated string
// with a debug ID for each node traversed
std::string GraphDFS(const graph::Graph &bgraph);

// Now BFS
std::string GraphBFS(const graph::Graph &bgraph);

void GraphNodeClear(const graph::Graph &bgraph);

std::string GraphDFSVisit(std::weak_ptr<graphnode::Node> node_ptr);

std::string GraphBFSVisit(std::queue<std::weak_ptr<graphnode::Node>> &node_ptr);

} // namespace algorithm

#endif // MKHALAF_LEARNINGCPP17_ALGORITHM
