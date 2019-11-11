#include "textreader.h"
#include "parsehelp/parsehelp.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>



namespace textreader {


TextReader::TextReader(const std::string &filename): filename_(filename) {
  textstream_.open(filename_);
}

std::vector<std::pair<unsigned int, std::optional <unsigned int>>> TextReader::GetAdjacency() const {
  return(adjvec_);
}



bool TextReader::CreateAdjacency() {

  std::string line;
  while (textstream_.good()) {
    if (std::getline(textstream_, line).good()) {

      std::optional<std::pair<unsigned int,std::optional<unsigned int>>> source_dest = parsehelp::ParseHelp::ProcessLine(line);

      if (!source_dest.has_value()) {
        return(false);
      }
      else {
        adjvec_.push_back(*source_dest);
      }
    }
  }

  // Did I process the entire file
  // if I exited before eof then something went wrong
  return (textstream_.eof());
}


TextReader::~TextReader() {
  // close the stream
  if (textstream_.is_open()) {
    textstream_.close();
  }
}



} // namespace textreader







