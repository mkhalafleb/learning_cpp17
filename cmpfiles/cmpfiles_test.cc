#include "cmpfiles.h"
#include "gtest/gtest.h"
#include <string>
#include <cstdlib>
#include <filesystem>

namespace {

// The fixture for testing class CmpFiles 
class CmpFilesTest : public ::testing::Test {
 public:
  static std::string FullPath(const std::string &endpath);
 protected:
};

std::string CmpFilesTest::FullPath(const std::string &endpath)  {
  std::filesystem::path basepath = std::getenv("TEST_SRCDIR");
  basepath /= std::filesystem::path(std::getenv("TEST_WORKSPACE"));
  basepath /= std::filesystem::path("textreader");
  basepath /= std::filesystem::path(endpath);
  return(basepath.string());
};

// Tests that the Foo::Bar() method does Abc.
TEST_F(CmpFilesTest, SAME_FILE) {
}

TEST_F(CmpFilesTest, DIFF_FILE) {
}

}  // namespace
