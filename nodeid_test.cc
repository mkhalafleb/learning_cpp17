#include "nodeid.h"
#include "gtest/gtest.h"

namespace {

// The fixture for testing class NodeId
class NodeIdTest : public ::testing::Test {
 protected:
};

// Checks that two nodes created with the same ID are equal
TEST_F(NodeIdTest, TwoNodesEqual) {
  nodeid::NodeId a(8), b(8);
  EXPECT_EQ(a,b);
}

// Checks that two nodes created with different IDs are Not equal
TEST_F(NodeIdTest, TwoNodesNotEqual) {
  nodeid::NodeId a(5), b(8);
  EXPECT_NE(a,b);
}

}  // namespace

