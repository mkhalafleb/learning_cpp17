#include "algorithm.h"
#include "graph/graph.h"
#include "graphcreator/graphcreator.h"
#include "testutils/testutils.h"
#include "gtest/gtest.h"
#include <filesystem>
#include <optional>
#include <string>

namespace {

// The fixture for testing class NodeId
class AlgorithmTest : public ::testing::Test {
protected:
};

// Tests that the Foo::Bar() method does Abc.
//
//
TEST_F(AlgorithmTest, GraphDFS) {

  graphcreator::GraphCreator creator(
      testutils::FullPath("algorithm", "basic_graph"));
  std::optional<graph::Graph> graph = creator.CreateGraph();
  EXPECT_TRUE(graph.has_value());
  std::string path = algorithm::GraphDFS(*graph);
  EXPECT_EQ(path, "4,2,0,1,5,8,7,6,9,");
}

TEST_F(AlgorithmTest, GraphBFS) {

  graphcreator::GraphCreator creator(
      testutils::FullPath("algorithm", "basic_graph"));
  std::optional<graph::Graph> graph = creator.CreateGraph();
  EXPECT_TRUE(graph.has_value());
  std::string path = algorithm::GraphBFS(*graph);
  EXPECT_EQ(path, "0,2,4,1,5,6,7,8,9,");
}
} // namespace
