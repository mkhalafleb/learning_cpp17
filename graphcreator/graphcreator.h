#ifndef MKHALAF_LEARNINGCPP17_GRAPHCREATOR
#define MKHALAF_LEARNINGCPP17_GRAPHCREATOR
#include <string>

namespace graphcreator {

class GraphCreator {
 public:
  // This is an absolute path for a file
  GraphCreator(const std::string &filename);

 private:
  std::string filename_;
};

} // namespace graphcreator


#endif  // MKHALAF_LEARNINGCPP17_GRAPHCREATOR
