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

TEST_F(NodeIdTest, SingleNodeNotValid) {
  nodeid::NodeId a(-1);
  nodeid::NodeId b(-2);
  EXPECT_FALSE(a.IsValid());
  EXPECT_FALSE(b.IsValid());
}

TEST_F(NodeIdTest, SingleNodeValid) {
  nodeid::NodeId a(1);
  EXPECT_TRUE(a.IsValid());
}

}  // namespace

