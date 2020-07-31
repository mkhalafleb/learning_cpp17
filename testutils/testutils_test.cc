#include "testutils.h"
#include "gtest/gtest.h"
#include <filesystem>
#include <string>

namespace {

// The fixture for testing class NodeId
class TestUtilsTest : public ::testing::Test {
protected:
};

// Tests that the Foo::Bar() method does Abc.
//
//
TEST_F(TestUtilsTest, basicpath_test) {

  std::string basicpath = testutils::FullPath("test", "basicpath");
  std::filesystem::path basepath = std::getenv("TEST_SRCDIR");
  basepath /= std::filesystem::path(std::getenv("TEST_WORKSPACE"));
  basepath /= std::filesystem::path("test");
  basepath /= std::filesystem::path("basicpath");
  EXPECT_EQ(basicpath, basepath);
}

} // namespace
