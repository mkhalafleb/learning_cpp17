#include "textdumper.h"
#include <string>
#include <optional>
#include <vector>
#include <fstream>
#include <utility>

namespace textdumper {

bool TextDumper::DumpList() {

  if (!textstream_.is_open()) {
    return (false);
  }

  std::pair<unsigned int, std::optional<unsigned int>> edge;
  for (auto iter=edgevector_.begin(); iter!=edgevector_.end();++iter) {
    edge = *iter;
    if (!textstream_.good()) {
      return(false);
    }
    textstream_ << edge.first  << ",";
    if (edge.second.has_value()) {
      textstream_ << *(edge.second);
    }
    textstream_ << std::endl;
  }
  return(textstream_.good());
}


TextDumper::TextDumper(const std::string &filename,
                       const std::vector<std::pair<unsigned int,
                                    std::optional<unsigned int>>> &edgevector)
                      : filename_(filename), edgevector_(std::move(edgevector)) {
  textstream_.open(filename_);
}


TextDumper::~TextDumper() {
  // close the stream
  if (textstream_.is_open()) {
    textstream_.close();
  }
}



} // namespace textdumper







