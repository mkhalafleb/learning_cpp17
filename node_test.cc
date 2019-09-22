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
}

TEST_F(NodeTest, TwoNodesFail) {
  std::shared_ptr<graphnode::Node> n_a = std::make_shared<graphnode::Node> (0);
  std::shared_ptr<graphnode::Node> n_b = std::make_shared<graphnode::Node> (1);
  std::shared_ptr<graphnode::Node> n_c = std::make_shared<graphnode::Node> (2);
  n_a->AddNeighbour(n_b);
  EXPECT_EXIT(n_a->AddNeighbour(n_c), ::testing::KilledBySignal(SIGABRT), "");
}



}  // namespace

