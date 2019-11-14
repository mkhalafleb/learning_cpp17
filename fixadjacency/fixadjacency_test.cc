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


TEST_F(FixAdjacencyTest, ILLEGALLIST) {
  std::vector<std::pair<unsigned int, std::optional<unsigned int>>> adjvec = {
    std::make_pair(0u, std::make_optional(4u)),
    std::make_pair(0u, std::make_optional(3u))
    };
  fixadjacency::FixAdjacency fixer(adjvec);
  EXPECT_FALSE(fixer.VerifyAdjacency());
}

TEST_F(FixAdjacencyTest, LEGALLIST) {
  std::vector<std::pair<unsigned int, std::optional<unsigned int>>> adjvec = {
    std::make_pair(1u, std::make_optional(4u)),
    std::make_pair(0u, std::make_optional(3u))
    };
  fixadjacency::FixAdjacency fixer(adjvec);
  EXPECT_TRUE(fixer.VerifyAdjacency());
  EXPECT_TRUE(fixer.RepairAdjacency());
  std::vector<std::pair<unsigned int, std::optional<unsigned int>>> adjvec_result = {
    std::make_pair(0u, std::make_optional(3u)),
    std::make_pair(1u, std::make_optional(4u)),
    std::make_pair(3u, std::nullopt),
    std::make_pair(4u, std::nullopt)
    };

  fixadjacency::FixAdjacency fixer2(adjvec_result);

  auto adjlist = fixer.GetAdjacency(); 
  auto adjlist2 = fixer2.GetAdjacency(); 

  EXPECT_TRUE(adjlist == adjlist2);

}

}  // namespace
