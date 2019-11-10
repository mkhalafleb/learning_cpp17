#ifndef MKHALAF_LEARNINGCPP17_TEXTDUMPER
#define MKHALAF_LEARNINGCPP17_TEXTDUMPER
#include <string>
#include <fstream>
#include <list>
#include <optional>
#include <utility>


namespace textdumper {

class TextDumper {
 public:
  TextDumper(const std::string &filename, 
             const std::list<std::pair<unsigned int, std::optional<unsigned int>>> &edgelist);

  bool DumpList();  // Can't be constant because it changes textstream_

  ~TextDumper();


 private:
  std::ofstream textstream_;
  std::string filename_;
  std::list<std::pair<unsigned int, std::optional<unsigned int>>> edgelist_;


};

} // namespace textdumper


#endif  // MKHALAF_LEARNINGCPP17_TEXTDUMPER
