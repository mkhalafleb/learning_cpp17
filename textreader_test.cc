#include "textreader.h"
#include "gtest/gtest.h"

namespace {

// The fixture for testing class TextReader 
class TextReaderTest : public ::testing::Test {
 protected:
};

// Tests that the Foo::Bar() method does Abc.
TEST_F(TextReaderTest, CREATENAME) {
  textreader::TextReader txtreader("Hello");
  EXPECT_TRUE(txtreader.CreateAdjacency());
 }

}  // namespace
