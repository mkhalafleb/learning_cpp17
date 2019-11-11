#include "fixadjacency.h"
#include <string>
#include <algorithm>
#include <set>



namespace fixadjacency {


FixAdjacency::FixAdjacency(const std::vector<std::pair<unsigned int, std::optional<unsigned int>>> &adjvec): adjvec_(std::move(adjvec)) {
}

std::list<std::pair<unsigned int, std::optional <unsigned int>>> FixAdjacency::GetAdjacency() const {
  return(std::list<std::pair<unsigned int, std::optional <unsigned int>>>(adjvec_.begin(), adjvec_.end()));
}


bool FixAdjacency::RepairAdjacency() {

  // Basically walk through each source and store it
  // Walk through each destination and if not found in vec, add it, don't add dups
  std::set<unsigned int> sources;

  auto add_set = [&sources] (std::pair<unsigned int, std::optional<unsigned int>> &edge) { sources.insert(edge.first); };


  std::for_each(adjvec_.begin(), adjvec_.end(), add_set);

  std::vector<std::pair<unsigned int, std::optional<unsigned int>>> added_list;

  auto add_edge = [&added_list, &sources] (std::pair<unsigned int, std::optional<unsigned int>> &edge) {
    if (!edge.second.has_value()) return;
    if ((sources.find(*(edge.second))) != sources.end()) return;
    // Add it
    added_list.push_back(std::make_pair(*(edge.second), std::nullopt));
  };

  std::for_each(adjvec_.begin(), adjvec_.end(), add_edge);

  adjvec_.insert(adjvec_.end(), added_list.begin(), added_list.end());

  // for each
  return(true);
}


bool FixAdjacency::VerifyAdjacency() {
  // One unique source for entire vector
  //
  // source vector on source
  std::sort(adjvec_.begin(), adjvec_.end(), FixAdjacency::VecPairSort);

  // use adjacent find for uniqueness, if no adjacent find then each element
  // is unique
  return(std::adjacent_find(adjvec_.begin(), adjvec_.end(), FixAdjacency::VecPairEqual) == adjvec_.end());
}



bool FixAdjacency::VecPairSort(std::pair<unsigned int, std::optional<unsigned int>> rec_a, std::pair<unsigned int, std::optional<unsigned int>> rec_b) {
  return(rec_a.first < rec_b.first);
}

bool FixAdjacency::VecPairEqual(std::pair<unsigned int, std::optional<unsigned int>> rec_a, std::pair<unsigned int, std::optional<unsigned int>> rec_b) {
  return(rec_a.first == rec_b.first);
}



} // namespace fixadjacency







