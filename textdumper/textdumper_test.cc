#include "textdumper.h"
#include "gtest/gtest.h"
#include <string>
#include <filesystem>
#include <cstdlib>
#include <list>
#include <optional>

namespace {

// The fixture for testing class TextDumper 
class TextDumperTest : public ::testing::Test {
 public:
  static std::string FullPath(const std::string &endpath) ;
 protected:
};



std::string TextDumperTest::FullPath(const std::string &endpath) {
  std::filesystem::path basepath = std::getenv("TEST_SRCDIR");
  basepath /= std::filesystem::path(std::getenv("TEST_WORKSPACE"));
  basepath /= std::filesystem::path("textdumper");
  basepath /= std::filesystem::path(endpath);
  return(basepath.string());
};

// Tests that the Foo::Bar() method does Abc.
TEST_F(TextDumperTest, BASETEST) {

// Create List
  std::list<std::pair<unsigned int, std::optional<unsigned int>>>  edgelist = {
    std::make_pair(2u,  std::make_optional<unsigned int> (4u)),
    std::make_pair(3u, std::nullopt)
  };

  textdumper::TextDumper txtreader(TextDumperTest::FullPath("basic_list_dump"), edgelist);
  EXPECT_TRUE(txtreader.DumpList());
  // Now compare the files

}



}  // namespace
