#include "textdumper.h"



namespace textdumper {

bool TextDumper::DumpList() {

  if (!textstream_.is_open()) {
    return (false);
  }

  std::pair<unsigned int, std::optional<unsigned int>> edge;
  for (auto iter=edgelist_.begin(); iter!=edgelist_.end();++iter) {
    edge = *iter;
    if (!textstream_.good()) {
      return(false);
    }
    textstream_ << "{" << edge.first  << ",";
    if (edge.second.has_value()) {
      textstream_ << *(edge.second);
    }
    textstream_ << "}," << std::endl;
  }
  return(textstream_.good());
}


TextDumper::TextDumper(const std::string &filename,
                       const std::list<std::pair<unsigned int,
                                    std::optional<unsigned int>>> &edgelist)
                      : filename_(filename), edgelist_(std::move(edgelist)) {
  textstream_.open(filename_);
}


TextDumper::~TextDumper() {
  // close the stream
  if (textstream_.is_open()) {
    textstream_.close();
  }
}



} // namespace textdumper







