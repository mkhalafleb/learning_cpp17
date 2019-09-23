#include <memory>
#include "node.h"
#include "gtest/gtest.h"

namespace {

// The fixture for testing class Node
class NodeTest : public ::testing::Test {
 protected:
};

TEST_F(NodeTest, TwoNodes) {
  std::shared_ptr<graphnode::Node> n_a = std::make_shared<graphnode::Node> (0);
  std::shared_ptr<graphnode::Node> n_b = std::make_shared<graphnode::Node> (1);
  n_a->AddNeighbour(n_b);

  EXPECT_TRUE((n_b->GetNeighbour()).expired());
  EXPECT_FALSE((n_a->GetNeighbour()).expired());
  std::shared_ptr<graphnode::Node> n_a_neighbour = n_a->GetNeighbour().lock();
  EXPECT_TRUE(n_a_neighbour);
  EXPECT_EQ(n_a_neighbour, n_b);
}

TEST_F(NodeTest, NodePointsToItself) {
  std::shared_ptr<graphnode::Node> n_a = std::make_shared<graphnode::Node> (0);
  n_a->AddNeighbour(n_a);
  EXPECT_FALSE((n_a->GetNeighbour()).expired());
  std::shared_ptr<graphnode::Node> n_a_neighbour = n_a->GetNeighbour().lock();
  EXPECT_TRUE(n_a_neighbour);
  EXPECT_EQ(n_a_neighbour, n_a);
}

TEST_F(NodeTest, TwoNodesFail) {
  std::shared_ptr<graphnode::Node> n_a = std::make_shared<graphnode::Node> (0);
  std::shared_ptr<graphnode::Node> n_b = std::make_shared<graphnode::Node> (1);
  std::shared_ptr<graphnode::Node> n_c = std::make_shared<graphnode::Node> (2);
  n_a->AddNeighbour(n_b);
  EXPECT_EXIT(n_a->AddNeighbour(n_c), ::testing::KilledBySignal(SIGABRT), "");
}



}  // namespace

