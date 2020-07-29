#include "algorithm.h"
#include "graph/graph.h"
#include "graphcreator/graphcreator.h"
#include "gtest/gtest.h"
#include <filesystem>
#include <optional>
#include <string>

namespace {

std::string FullPath(const std::string &endpath) {
  std::filesystem::path basepath = std::getenv("TEST_SRCDIR");
  basepath /= std::filesystem::path(std::getenv("TEST_WORKSPACE"));
  basepath /= std::filesystem::path("algorithm");
  basepath /= std::filesystem::path(endpath);
  return (basepath.string());
};

// The fixture for testing class NodeId
class AlgorithmTest : public ::testing::Test {
protected:
};

// Tests that the Foo::Bar() method does Abc.
//
//
TEST_F(AlgorithmTest, GraphDFS) {

  graphcreator::GraphCreator creator(FullPath("basic_graph"));
  std::optional<graph::Graph> graph = creator.CreateGraph();
  EXPECT_TRUE(graph.has_value());
  std::string path = algorithm::GraphDFS(*graph);
  EXPECT_EQ(path, "4,2,0,1,5,8,7,6,9,");
}

TEST_F(AlgorithmTest, GraphBFS) {

  graphcreator::GraphCreator creator(FullPath("basic_graph"));
  std::optional<graph::Graph> graph = creator.CreateGraph();
  EXPECT_TRUE(graph.has_value());
  std::string path = algorithm::GraphBFS(*graph);
  EXPECT_EQ(path, "0,2,4,1,5,6,7,8,9,");
}
} // namespace
