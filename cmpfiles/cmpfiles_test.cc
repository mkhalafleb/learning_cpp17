#include "cmpfiles.h"
#include "gtest/gtest.h"
#include <string>
#include <cstdlib>
#include <filesystem>
#include <optional>

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
  basepath /= std::filesystem::path("cmpfiles");
  basepath /= std::filesystem::path(endpath);
  return(basepath.string());
};

// Tests that the Foo::Bar() method does Abc.
TEST_F(CmpFilesTest, SAME_FILE) {
  cmpfiles::CmpFiles compare2(CmpFilesTest::FullPath("basic_list"), CmpFilesTest::FullPath("basic_list"));
  EXPECT_FALSE(compare2.FilesEqual().has_value());

}

TEST_F(CmpFilesTest, DIFF_FILE) {
  cmpfiles::CmpFiles compare2(CmpFilesTest::FullPath("basic_list"), CmpFilesTest::FullPath("basic_list_dup"));

  std::optional<std::string> cmp_string = compare2.FilesEqual();
  EXPECT_TRUE(cmp_string.has_value());
  EXPECT_TRUE(*cmp_string == "2,5"); // File A smaller than File B

}

}  // namespace
