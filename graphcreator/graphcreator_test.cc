#include "graphcreator.h"
#include "gtest/gtest.h"
#include "graph/graph.h"
#include <optional>
#include <filesystem>

namespace {

// The fixture for testing class TextReader 
class GraphCreatorTest : public ::testing::Test {
 public:
  static std::string FullPath(const std::string &endpath) ;
 protected:
};

std::string GraphCreatorTest::FullPath(const std::string &endpath) {
  std::filesystem::path basepath = std::getenv("TEST_SRCDIR");
  basepath /= std::filesystem::path(std::getenv("TEST_WORKSPACE"));
  basepath /= std::filesystem::path("graphcreator");
  basepath /= std::filesystem::path(endpath);
  return(basepath.string());
};

TEST_F(GraphCreatorTest, GRAPH) {
  graphcreator::GraphCreator gcreator(GraphCreatorTest::FullPath("basic_graph"));
  std::optional<graph::Graph> bgraph =  gcreator.CreateGraph();

  EXPECT_TRUE(bgraph.has_value());



}


}  // namespace
