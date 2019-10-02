#include "textreader.h"
#include <fstream>
#include <string>



namespace textreader {


TextReader::TextReader(const std::string &filename): filename_(filename) {
  textstream_.open(filename_);
}


bool TextReader::CreateAdjacency() {

  std::string line;
  while (textstream_.good()) {
    if (!std::getline(textstream_, line).good()) {
      return(false);
    } else {
      // Now process the line
      std::pair<bool, std::optional<std::pair<unsigned int,std::optional<unsigned int>>>> source_dest = ProcessLine(line);

      if (!source_dest.first) {
        return(false);
      }
      else {
        adjlist_.push_back(*(source_dest.second));
      }
    }
  }

  // Did I process the entire file
  // if I exited before eof then something went wrong
  return (textstream_.eof());
}

bool TextReader::VerifyAdjacency() {
  // One unique source for entire vector
  //
  // source vector on source
  return(true);
}


std::pair<bool, std::optional<std::pair<unsigned int,std::optional<unsigned int>>>> TextReader::ProcessLine(const std::string &line) const {
  return(std::make_pair(false, std::nullopt));
}




TextReader::~TextReader() {
  // close the stream
  if (textstream_.is_open()) {
    textstream_.close();
  }
}



} // namespace textreader







