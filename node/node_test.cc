#include <memory>
#include "node.h"
#include "gtest/gtest.h"

namespace {

// The fixture for testing class Node
class NodeTest : public ::testing::Test {
 protected:
};

TEST_F(NodeTest, TwoNodes) {
  std::shared_ptr<graphnode::Node> n_a = std::make_shared<graphnode::Node> (graphnode::Node::DualId {0, 5});
  std::shared_ptr<graphnode::Node> n_b = std::make_shared<graphnode::Node> (graphnode::Node::DualId {1, 8});
  EXPECT_EQ(n_a->GetIds().nodeid_,nodeid::NodeId(0));
  EXPECT_EQ(n_a->GetIds().original_id_,nodeid::NodeId(5));
  EXPECT_EQ(n_b->GetIds().nodeid_,nodeid::NodeId(1));
  EXPECT_EQ(n_b->GetIds().original_id_,nodeid::NodeId(8));
  EXPECT_FALSE(n_a->HasNeighbour());
  EXPECT_FALSE(n_b->HasNeighbour());
  n_a->AddNeighbour(n_b);


  EXPECT_FALSE(n_b->HasNeighbour());
  EXPECT_TRUE(n_a->HasNeighbour());
  std::shared_ptr<graphnode::Node> n_a_neighbour = n_a->GetNeighbour().lock();
  EXPECT_TRUE(n_a_neighbour);
  EXPECT_EQ(n_a_neighbour, n_b);
}

TEST_F(NodeTest, NodePointsToItself) {
  std::shared_ptr<graphnode::Node> n_a = std::make_shared<graphnode::Node> (graphnode::Node::DualId {0, 1});
  EXPECT_FALSE(n_a->HasNeighbour());
  n_a->AddNeighbour(n_a);
  EXPECT_TRUE(n_a->HasNeighbour());
  std::shared_ptr<graphnode::Node> n_a_neighbour = n_a->GetNeighbour().lock();
  EXPECT_TRUE(n_a_neighbour);
  EXPECT_EQ(n_a_neighbour, n_a);
}

TEST_F(NodeTest, TwoNodesFail) {
  std::shared_ptr<graphnode::Node> n_a = std::make_shared<graphnode::Node> (graphnode::Node::DualId {0, 1});
  std::shared_ptr<graphnode::Node> n_b = std::make_shared<graphnode::Node> (graphnode::Node::DualId {1, 2});
  std::shared_ptr<graphnode::Node> n_c = std::make_shared<graphnode::Node> (graphnode::Node::DualId {2, 3});
  EXPECT_FALSE(n_a->HasNeighbour());
  EXPECT_FALSE(n_b->HasNeighbour());
  EXPECT_FALSE(n_c->HasNeighbour());
  n_a->AddNeighbour(n_b);
  EXPECT_TRUE(n_a->HasNeighbour());
  EXPECT_EXIT(n_a->AddNeighbour(n_c), ::testing::KilledBySignal(SIGABRT), "");
}



}  // namespace

