#include "textdumper.h"
#include "gtest/gtest.h"
#include "cmpfiles/cmpfiles.h"
#include <string>
#include <filesystem>
#include <cstdlib>
#include <vector>
#include <optional>

namespace {

// The fixture for testing class TextDumper 
class TextDumperTest : public ::testing::Test {
 public:
  static std::string FullPath(const std::string &endpath) ;
  static bool DumpFile(const std::string &fullpath,
                       const std::vector<std::pair<unsigned int, std::optional<unsigned int>>> &edgevec);
 protected:
};



std::string TextDumperTest::FullPath(const std::string &endpath) {
  std::filesystem::path basepath = std::getenv("TEST_SRCDIR");
  basepath /= std::filesystem::path(std::getenv("TEST_WORKSPACE"));
  basepath /= std::filesystem::path("textdumper");
  basepath /= std::filesystem::path(endpath);
  return(basepath.string());
};

bool TextDumperTest::DumpFile(const std::string &fullpath, const std::vector<std::pair<unsigned int, std::optional<unsigned int>>> &edgevec) {

  textdumper::TextDumper txtdumper(fullpath, edgevec);
  return(txtdumper.DumpList());
}

// Tests that the Foo::Bar() method does Abc.
TEST_F(TextDumperTest, BASETESTEQUAL) {

// Create List
  std::vector<std::pair<unsigned int, std::optional<unsigned int>>>  edgevec = {
    std::make_pair(2u,  std::make_optional<unsigned int> (4u)),
    std::make_pair(0u,  std::make_optional<unsigned int> (2u)),
    std::make_pair(4u, std::nullopt)
  };

  EXPECT_TRUE(TextDumperTest::DumpFile(TextDumperTest::FullPath("basic_list_dump"), edgevec));

  cmpfiles::CmpFiles comparator(TextDumperTest::FullPath("basic_list_dump"),
                     TextDumperTest::FullPath("basic_list"));

  EXPECT_FALSE(comparator.FilesEqual().has_value());

}

TEST_F(TextDumperTest, BASETESTNOTEQUAL) {

// Create List
  std::vector<std::pair<unsigned int, std::optional<unsigned int>>>  edgevec = {
    std::make_pair(2u,  std::make_optional<unsigned int> (4u)),
    std::make_pair(1u,  std::make_optional<unsigned int> (2u)),
    std::make_pair(4u, std::nullopt)
  };

  EXPECT_TRUE(TextDumperTest::DumpFile(TextDumperTest::FullPath("basic_list_dump2"), edgevec));

  cmpfiles::CmpFiles comparator(TextDumperTest::FullPath("basic_list_dump2"),
                     TextDumperTest::FullPath("basic_list"));


  std::optional<std::string> cmpvalue = comparator.FilesEqual();
  EXPECT_TRUE(cmpvalue.has_value());
  EXPECT_TRUE(*cmpvalue == "1,20,2");

}






}  // namespace
