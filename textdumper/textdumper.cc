#include "textdumper.h"



namespace textdumper {


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







