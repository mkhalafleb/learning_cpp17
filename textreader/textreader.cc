#include "textreader.h"
#include "parsehelp/parsehelp.h"
#include <fstream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <string_view>
#include <iostream>



namespace textreader {


TextReader::TextReader(const std::string &filename): filename_(filename) { 
  textstream_.open(filename_);
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
        adjlist_.push_back(*source_dest);
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
  std::sort(adjlist_.begin(), adjlist_.end(), TextReader::VecPairSort);

  // use adjacent find for uniqueness, if no adjacent find then each element
  // is unique
  return(std::adjacent_find(adjlist_.begin(), adjlist_.end(), TextReader::VecPairEqual) == adjlist_.end());
}



bool TextReader::VecPairSort(std::pair<unsigned int, std::optional<unsigned int>> rec_a, std::pair<unsigned int, std::optional<unsigned int>> rec_b) {
  return(rec_a.first < rec_b.first);
}

bool TextReader::VecPairEqual(std::pair<unsigned int, std::optional<unsigned int>> rec_a, std::pair<unsigned int, std::optional<unsigned int>> rec_b) {
  return(rec_a.first == rec_b.first);
}

TextReader::~TextReader() {
  // close the stream
  if (textstream_.is_open()) {
    textstream_.close();
  }
}



} // namespace textreader







