#ifndef MKHALAF_LEARNINGCPP17_PARSEHELP
#define MKHALAF_LEARNINGCPP17_PARSEHELP
#include <string>
#include <optional>
#include <string_view>


namespace parsehelp {

class ParseHelp {
 public:



  static bool IsAllBlank(const std::string &str);

  static std::optional<unsigned int> ExtractInt(std::string_view number);

  static std::optional<std::pair<unsigned int, std::optional<unsigned int>>> ProcessLine(const std::string &line);

};

} // namespace parsehelp


#endif  // MKHALAF_LEARNINGCPP17_PARSEHELP
