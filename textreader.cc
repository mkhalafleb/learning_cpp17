#include "textreader.h"
#include <fstream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <string_view>



namespace textreader {


TextReader::TextReader(const std::string &filename): filename_(filename) {
  textstream_.open(filename_);
}


std::optional<unsigned int> TextReader::ExtractInt(std::string_view number) {


  // Need to add the fact null is real and all whitespace is real
  try {
    std::string num(number);
    std::string::size_type loc;
    int i_dec = std::stoi(num, &loc);
    if ((loc == std::string::npos) && (i_dec >= 0)) {
      return(i_dec);
    } 
    else {
      // Need to Understand what null string or all white space does
      return(std::numeric_limits<unsigned int>::max());
    }
  }
  catch (std::invalid_argument) {
    return(std::numeric_limits<unsigned int>::max());
  }
  catch (std::out_of_range) {
    return(std::numeric_limits<unsigned int>::max());
  }
}

bool TextReader::CreateAdjacency() {

  std::string line;
  while (textstream_.good()) {
    if (!std::getline(textstream_, line).good()) {
      return(false);
    } else {
      // Now process the line
      std::optional<std::pair<unsigned int,std::optional<unsigned int>>> source_dest = TextReader::ProcessLine(line);

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


std::optional<std::pair<unsigned int,std::optional<unsigned int>>> TextReader::ProcessLine(const std::string &line) {


  // The format is (int, [int|nothing]) per line
  std::string::size_type comma = line.find(',');
  if (comma  == std::string::npos)  {
    // No Comma found
    return(std::nullopt);
  } else {
    // split string in half at comma
    std::string_view  source(line.substr(0, comma));
    std::string_view  dest(line.substr(comma+1, (line.size() - (comma+1))));

    // now convert them to integer and make sure it is pure
    std::optional<unsigned int> source_i = TextReader::ExtractInt(source);
    std::optional<unsigned int> dest_i = TextReader::ExtractInt(dest);

    bool valid_source = source_i.has_value() && (*source_i != std::numeric_limits<unsigned int>::max());
    bool valid_dest = (dest_i.has_value() && (*dest_i != std::numeric_limits<unsigned int>::max())) || (!dest_i.has_value());
    // We need to build the real number
    if (!valid_source) {
      return(std::nullopt);
    } else if (valid_dest) {
      return(std::make_pair(*source_i, *dest_i));
    } else {
      return(std::make_pair(*source_i, std::nullopt));
    }

  }
  return(std::nullopt);
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







