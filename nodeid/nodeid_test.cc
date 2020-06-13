#include <limits>
#include "nodeid.h"
#include "gtest/gtest.h"

namespace {

// The fixture for testing class NodeId
class NodeIdTest : public ::testing::Test {
 protected:
};

// Tests that the Foo::Bar() method does Abc.
TEST_F(NodeIdTest, TwoNodesEqual) {
  nodeid::NodeId a(8), b(8);
  EXPECT_EQ(a,b);
}

TEST_F(NodeIdTest, TwoNodesNotEqual) {
  nodeid::NodeId a(5), b(8);
  EXPECT_NE(a,b);
}

TEST_F(NodeIdTest, NodeInvalid) {
  nodeid::NodeId a(-1);
  EXPECT_FALSE(a.IsValid());
}

TEST_F(NodeIdTest, Nodevalid) {
  nodeid::NodeId a(2);
  EXPECT_TRUE(a.IsValid());
}

TEST_F(NodeIdTest, Nodelarge) {
  unsigned int big = static_cast<unsigned int> (std::numeric_limits<int>::max())  + 1;
  nodeid::NodeId a(big);
  EXPECT_FALSE(a.IsValid());
}

}  // namespace
