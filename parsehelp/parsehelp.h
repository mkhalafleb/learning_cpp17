#ifndef MKHALAF_LEARNINGCPP17_PARSEHELP
#define MKHALAF_LEARNINGCPP17_PARSEHELP
#include <string>
#include <optional>


namespace parsehelp {

class ParseHelp {
 public:



  static bool IsAllBlank(const std::string &str);

  static std::optional<unsigned int> ExtractInt(const std::string &number);

  static std::optional<std::pair<unsigned int, std::optional<unsigned int>>> ProcessLine(const std::string &line);

};

} // namespace parsehelp


#endif  // MKHALAF_LEARNINGCPP17_PARSEHELP
