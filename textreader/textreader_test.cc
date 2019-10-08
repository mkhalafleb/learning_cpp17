#include "textreader.h"
#include "gtest/gtest.h"
#include <string>
#include <iostream>

namespace {

// The fixture for testing class TextReader 
class TextReaderTest : public ::testing::Test {
 protected:
};

// Tests that the Foo::Bar() method does Abc.
TEST_F(TextReaderTest, CREATENAME) {
  std::string test_src = getenv("TEST_SRCDIR");
  std::string test_workspace = getenv("TEST_WORKSPACE");
  test_src += "/" + test_workspace + "/textreader/Hello";
  textreader::TextReader txtreader(test_src);
  EXPECT_TRUE(txtreader.CreateAdjacency());
  EXPECT_TRUE(txtreader.VerifyAdjacency());
 }

}  // namespace
