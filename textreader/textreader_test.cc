#include "textreader.h"
#include "gtest/gtest.h"
#include <string>
#include <cstdlib>
#include <filesystem>
#include <iostream>

namespace {

// The fixture for testing class TextReader 
class TextReaderTest : public ::testing::Test {
 public:
  static std::string FullPath(const std::string &endpath);
  static void PrintList(const std::pair<unsigned int, std::optional<unsigned int>> &node);
 protected:
};

std::string TextReaderTest::FullPath(const std::string &endpath)  {
  std::filesystem::path basepath = std::getenv("TEST_SRCDIR");
  basepath /= std::filesystem::path(std::getenv("TEST_WORKSPACE"));
  basepath /= std::filesystem::path("textreader");
  basepath /= std::filesystem::path(endpath);
  return(basepath.string());
};

void TextReaderTest::PrintList(const std::pair<unsigned int, std::optional<unsigned int>> &node) {
  std::string dest = node.second.has_value() ? std::to_string(*(node.second)) : "";
  std::cout << "*" << node.first << "," << dest << "*" << std::endl;
}


// Tests that the Foo::Bar() method does Abc.
TEST_F(TextReaderTest, CREATENAME) {
  textreader::TextReader txtreader(TextReaderTest::FullPath("basic_list"));
  EXPECT_TRUE(txtreader.CreateAdjacency());

  // For Now just print the list
  auto adjlist = txtreader.GetAdjacency();

  // basic_list has
  // {2,4}, {0,2}., 4,

  std::vector<std::pair<unsigned int, std::optional<unsigned int>>> cmpvec = {
    std::make_pair(2u, std::make_optional(4u)),
    std::make_pair(0u, std::make_optional(2u)),
    std::make_pair(4u, std::nullopt)
  };

  EXPECT_TRUE(adjlist == cmpvec);

}

TEST_F(TextReaderTest, CREATENAMEDUP) {
  textreader::TextReader txtreader(TextReaderTest::FullPath("basic_list_dup"));
  EXPECT_TRUE(txtreader.CreateAdjacency());

  // For Now just print the list
  auto adjlist = txtreader.GetAdjacency();

  // basic_list has
  // {2,4}, {0,2}., {4,}, {2,5}

  std::vector<std::pair<unsigned int, std::optional<unsigned int>>> cmpvec = {
    std::make_pair(2u, std::make_optional(4u)),
    std::make_pair(0u, std::make_optional(2u)),
    std::make_pair(4u, std::nullopt),
    std::make_pair(2u, std::make_optional(5u))
  };

  EXPECT_TRUE(adjlist == cmpvec);

  std::vector<std::pair<unsigned int, std::optional<unsigned int>>> cmpvec2 = {
    std::make_pair(2u, std::make_optional(4u)),
    std::make_pair(0u, std::make_optional(2u)),
    std::make_pair(4u, std::nullopt),
    std::make_pair(2u, std::make_optional(4u)) // Changed 5 to  4
  };

  EXPECT_FALSE(adjlist == cmpvec2);

}

}  // namespace
