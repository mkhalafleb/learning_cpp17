#include "textreader.h"
#include "parsehelp/parsehelp.h"
#include <fstream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <string_view>
#include <iostream>
#include <set>



namespace textreader {


TextReader::TextReader(const std::string &filename): filename_(filename) { 
  textstream_.open(filename_);
}

std::list<std::pair<unsigned int, std::optional <unsigned int>>> TextReader::GetAdjacency() const {
  return(std::list<std::pair<unsigned int, std::optional <unsigned int>>>(adjlist_.begin(), adjlist_.end()));
}


bool TextReader::RepairAdjacency() {

  // Basically walk through each source and store it
  // Walk through each destination and if not found in vec, add it, don't add dups
  std::set<unsigned int> sources;

  auto add_set = [&sources] (std::pair<unsigned int, std::optional<unsigned int>> &edge) { sources.insert(edge.first); };


  std::for_each(adjlist_.begin(), adjlist_.end(), add_set); 

  std::vector<std::pair<unsigned int, std::optional<unsigned int>>> added_list;

  auto add_edge = [&added_list, &sources] (std::pair<unsigned int, std::optional<unsigned int>> &edge) {
    if (!edge.second.has_value()) return;
    if ((sources.find(*(edge.second))) != sources.end()) return;
    // Add it 
    added_list.push_back(std::make_pair(*(edge.second), std::nullopt)); 
  };

  std::for_each(adjlist_.begin(), adjlist_.end(), add_edge); 

  adjlist_.insert(adjlist_.end(), added_list.begin(), added_list.end());
    

  // for each 
  return(true);
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







