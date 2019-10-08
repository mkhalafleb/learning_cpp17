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
  std::string test_file = getenv("TEST_SRCDIR");
  test_file += "/workspace/textreader/Hello";
  std::cout << "*" << test_file << "*" << std::endl;
  textreader::TextReader txtreader(test_file);
  EXPECT_TRUE(txtreader.CreateAdjacency());
  EXPECT_TRUE(txtreader.VerifyAdjacency());
 }

}  // namespace
