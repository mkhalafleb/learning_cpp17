#include "textreader.h"
#include <fstream>
#include <string>
#include <algorithm>



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
  std::sort(adjlist_.begin(), adjlist_.end(), TextReader::VecPairSort);
  // source vector on source
  return(true);
}


std::pair<bool, std::optional<std::pair<unsigned int,std::optional<unsigned int>>>> TextReader::ProcessLine(const std::string &line) const {
  return(std::make_pair(false, std::nullopt));
}



bool TextReader::VecPairSort(std::pair<unsigned int, std::optional<unsigned int>> rec_a, std::pair<unsigned int, std::optional<unsigned int>> rec_b) {
  return(rec_a.first < rec_a.second);
}

TextReader::~TextReader() {
  // close the stream
  if (textstream_.is_open()) {
    textstream_.close();
  }
}



} // namespace textreader







