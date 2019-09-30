#include "textreader.h"
#include <fstream>
#include <string>



namespace textreader {


TextReader::TextReader(const std::string &filename): filename_(filename) {}



TextReader::~TextReader() {
  // close the stream
  textstream_.close();

}



} // namespace textreader







