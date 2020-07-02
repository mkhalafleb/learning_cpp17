#include "graph.h"
#include "graphcreator/graphcreator.h"
#include "node/node.h"
#include "gtest/gtest.h"
#include <filesystem>
#include <list>
#include <memory>
#include <optional>
#include <string>

namespace {

// The fixture for testing class Node
class GraphTest : public ::testing::Test {
public:
  static std::string FullPath(const std::string &endpath);

protected:
};

std::string GraphTest::FullPath(const std::string &endpath) {
  std::filesystem::path basepath = std::getenv("TEST_SRCDIR");
  basepath /= std::filesystem::path(std::getenv("TEST_WORKSPACE"));
  basepath /= std::filesystem::path("graph");
  basepath /= std::filesystem::path(endpath);
  return (basepath.string());
};

TEST_F(GraphTest, BasicGraph) {
  // Build the graph from a file
  graphcreator::GraphCreator gcreator(GraphTest::FullPath("basic_graph"));
  std::optional<graph::Graph> bgraph = gcreator.CreateGraph();

  EXPECT_TRUE(bgraph.has_value());
  // Now list the nodes
  const std::list<std::weak_ptr<graphnode::Node>> nodelist =
      bgraph->GetNodeList();

  std::string nodenames("");
  for (const auto &node : nodelist) {
    auto sp = node.lock();
    nodenames += std::to_string((sp->GetIds().original_id_).GetDebugId()) + ",";
  }
  EXPECT_EQ(nodenames, "0,1,2,4,");
}

} // namespace
