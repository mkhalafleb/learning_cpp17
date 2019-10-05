#include "parsehelp.h"
#include "gtest/gtest.h"
#include <string>
#include <optional>

namespace {

// The fixture for testing class TextReader 
class ParseHelpTest : public ::testing::Test {
 protected:
};

// Tests that the Foo::Bar() method does Abc.
TEST_F(ParseHelpTest, ALLBLANK) {
  std::string one_space(" ");
  std::string empty_s("");
  std::string two_space("  ");
  std::string two_space7("7  ");
  std::string two_space_u("  u");

 EXPECT_TRUE(parsehelp::ParseHelp::IsAllBlank(one_space));
 EXPECT_TRUE(parsehelp::ParseHelp::IsAllBlank(empty_s));
 EXPECT_TRUE(parsehelp::ParseHelp::IsAllBlank(two_space));
 EXPECT_FALSE(parsehelp::ParseHelp::IsAllBlank(two_space7));
 EXPECT_FALSE(parsehelp::ParseHelp::IsAllBlank(two_space_u));
 }

TEST_F(ParseHelpTest, NUMSTRING) {
  std::string s25("25");
  std::string s25_x("25x");
  std::string x_s25("x25");
  std::string x_neg("-24");
  std::string x_space_24(" 24");
  std::string x_24_space("24 ");

  constexpr unsigned int max_i = std::numeric_limits<unsigned int>::max();
  EXPECT_EQ(*(parsehelp::ParseHelp::ExtractInt(s25)), 25);
  EXPECT_EQ(*(parsehelp::ParseHelp::ExtractInt(s25_x)), max_i);
  EXPECT_EQ(*(parsehelp::ParseHelp::ExtractInt(x_s25)), max_i);
  EXPECT_EQ(*(parsehelp::ParseHelp::ExtractInt(x_neg)), max_i);
  EXPECT_EQ(*(parsehelp::ParseHelp::ExtractInt(x_space_24)), 24);
  EXPECT_EQ(*(parsehelp::ParseHelp::ExtractInt(x_24_space)), 24);
}

TEST_F(ParseHelpTest, ALLBLANKNULL) {
  std::string one_space(" ");
  std::string empty_s("");
  std::string two_space("  ");
  EXPECT_FALSE(parsehelp::ParseHelp::ExtractInt(one_space).has_value());
  EXPECT_FALSE(parsehelp::ParseHelp::ExtractInt(empty_s).has_value());
  EXPECT_FALSE(parsehelp::ParseHelp::ExtractInt(two_space).has_value());
}

TEST_F(ParseHelpTest, FULLLINEGOOD) {
  std::optional<std::pair<unsigned int, std::optional<unsigned int>>> p24
    = parsehelp::ParseHelp::ProcessLine("24,25");
  EXPECT_EQ(*(p24), std::make_pair(24u,std::make_optional<unsigned int>(25)));
}

TEST_F(ParseHelpTest, FULLLINEGOOD_DESTEMPTY) {
  std::optional<std::pair<unsigned int, std::optional<unsigned int>>> p24
    = parsehelp::ParseHelp::ProcessLine("24,");
  std::optional<std::pair<unsigned int, std::optional<unsigned int>>> p24_result = std::make_pair(24u, std::nullopt);
  EXPECT_EQ(*(p24), p24_result);
}

TEST_F(ParseHelpTest, FULLLINE_BADSRC) {
  std::optional<std::pair<unsigned int, std::optional<unsigned int>>> p24
    = parsehelp::ParseHelp::ProcessLine("x24,BLA");
  EXPECT_FALSE(p24.has_value());
}


TEST_F(ParseHelpTest, FULLLINE_BADDEST) {
  std::optional<std::pair<unsigned int, std::optional<unsigned int>>> p24
    = parsehelp::ParseHelp::ProcessLine("24,xBLA");
  EXPECT_FALSE(p24.has_value());
}




}  // namespace

