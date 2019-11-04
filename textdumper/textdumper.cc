#include "textdumper.h"



namespace textdumper {


TextDumper::TextDumper(const std::string &filename): filename_(filename) { 
  textstream_.open(filename_);
}


TextDumper::~TextDumper() {
  // close the stream
  if (textstream_.is_open()) {
    textstream_.close();
  }
}



} // namespace textdumper







