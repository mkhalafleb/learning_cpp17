#ifndef MKHALAF_LEARNINGCPP17_TEXTREADER
#define MKHALAF_LEARNINGCPP17_TEXTREADER
#include <fstream>
#include <string>
#include <vector>
#include <optional>
#include <utility>


namespace textreader {

// Reads a text file with pair seperated by a comma on each line
// that does the adjacency list of a degenerate graph
// {2,}, {3,4} means that node 2 does not point to anything and node 3 points
// to 4. Graph is degenerate as it has only one next pointer
// This class all it does is read the text file and stores it into a vector
class TextReader {
 public:
  TextReader(const std::string &filename);

  bool CreateAdjacency();

  std::vector<std::pair<unsigned int, std::optional <unsigned int>>> GetAdjacency() const;

  ~TextReader();


 private:

  std::string filename_;
  std::ifstream textstream_;
  std::vector<std::pair<unsigned int, std::optional <unsigned int>>> adjvec_;

};

} // namespace textreader


#endif  // MKHALAF_LEARNINGCPP17_TEXTREADER
