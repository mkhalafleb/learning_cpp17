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
  // source vector on source
  std::sort(adjlist_.begin(), adjlist_.end(), TextReader::VecPairSort);

  // use adjacent find for uniqueness, if no adjacent find then each element
  // is unique
  return(std::adjacent_find(adjlist_.begin(), adjlist_.end(), TextReader::VecPairEqual) == adjlist_.end());
}


std::pair<bool, std::optional<std::pair<unsigned int,std::optional<unsigned int>>>> TextReader::ProcessLine(const std::string &line) {


  // The format is (int, [int|nothing]) per line
  std::string::size_type comma = line.find(','); 
  if (comma  == std::string::npos)  {
    // No Comma found
    return(std::make_pair(false, std::nullopt));
  } else {
    // split string in half at comma
    std::string_view  source = line.substr(0, comma);
    std::string_view  dest = line.substr(comma+1, (line.size() - (comma+1)));

    // now convert them to integer and make sure it is pure

  }
  return(std::make_pair(false, std::nullopt));
}



bool TextReader::VecPairSort(std::pair<unsigned int, std::optional<unsigned int>> rec_a, std::pair<unsigned int, std::optional<unsigned int>> rec_b) {
  return(rec_a.first < rec_a.first);
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







