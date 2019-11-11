#ifndef MKHALAF_LEARNINGCPP17_CMPFILES
#define MKHALAF_LEARNINGCPP17_CMPFILES
#include <fstream>
#include <string>


namespace cmpfiles {

class CmpFiles {
 public:
  CmpFiles(const std::string &filename1, const std::string &filename2);

  // Returns null if they are equal otherwise returns a line that is a concat of
  // the first difference
  std::string FilesEqual();


  ~CmpFiles();

 private:

  std::string filename1_, filename2_;
  std::ifstream textstream1_, textstream2_;

};

} // namespace cmpfiles


#endif  // MKHALAF_LEARNINGCPP17_CMPFILES
