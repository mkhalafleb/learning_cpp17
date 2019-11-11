#include "fixadjacency.h"
#include "gtest/gtest.h"

namespace {

// The fixture for testing class TextReader 
class FixAdjacencyTest : public ::testing::Test {
 public:
  static void PrintList(const std::pair<unsigned int, std::optional<unsigned int>> &node);
 protected:
};


void FixAdjacencyTest::PrintList(const std::pair<unsigned int, std::optional<unsigned int>> &node) {
  std::string dest = node.second.has_value() ? std::to_string(*(node.second)) : "";
  std::cout << "*" << node.first << "," << dest << "*" << std::endl;
}


TEST_F(FixAdjacencyTest, CREATENAME) {
}

}  // namespace
