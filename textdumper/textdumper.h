#ifndef MKHALAF_LEARNINGCPP17_TEXTDUMPER
#define MKHALAF_LEARNINGCPP17_TEXTDUMPER
#include <string>
#include <fstream>


namespace textdumper {

class TextDumper {
 public:
  TextDumper(const std::string &filename);


  ~TextDumper();


 private:
  std::ofstream textstream_;
  std::string filename_;


};

} // namespace textdumper


#endif  // MKHALAF_LEARNINGCPP17_TEXTDUMPER
