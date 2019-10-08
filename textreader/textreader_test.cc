#include "textreader.h"
#include "gtest/gtest.h"
#include <string>
#include <cstdlib>
#include <filesystem>

namespace {

// The fixture for testing class TextReader 
class TextReaderTest : public ::testing::Test {
 public:
  static std::string FullPath(const std::string &endpath);
 protected:
};

std::string TextReaderTest::FullPath(const std::string &endpath) {
  std::filesystem::path basepath = std::getenv("TEST_SRCDIR");
  basepath /= std::filesystem::path(std::getenv("TEST_WORKSPACE"));
  basepath /= std::filesystem::path("textreader");
  basepath /= std::filesystem::path(endpath);
  return(basepath.string());
};

// Tests that the Foo::Bar() method does Abc.
TEST_F(TextReaderTest, CREATENAME) {
  textreader::TextReader txtreader(TextReaderTest::FullPath("Hello"));
  EXPECT_TRUE(txtreader.CreateAdjacency());
  EXPECT_TRUE(txtreader.VerifyAdjacency());
 }

}  // namespace
