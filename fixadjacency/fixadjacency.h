#ifndef MKHALAF_LEARNINGCPP17_FIXADJACENCY
#define MKHALAF_LEARNINGCPP17_FIXADJACENCY
#include <vector>
#include <optional>
#include <utility>
#include <list>


namespace fixadjacency {

class FixAdjacency {
 public:
  FixAdjacency(const std::vector<std::pair<unsigned int, std::optional<unsigned int>>> &adjvec );


  // Check if the adjacency vector has any duplicates since we are modelling
  // a degenerate graph with only a maximum of 1 edge
  bool VerifyAdjacency();

  // If there are node destinations that are found not to have any entries in the list then add them with blank destinations
  // Then re-sort the graph
  bool RepairAdjacency();

  // Return the adjacency as a sorted adjacency list
  std::list<std::pair<unsigned int, std::optional <unsigned int>>> GetAdjacency() const;


 private:

  static bool VecPairSort(std::pair<unsigned int, std::optional<unsigned int>> rec_a, std::pair<unsigned int, std::optional<unsigned int>> rec_b);

  static bool VecPairEqual(std::pair<unsigned int, std::optional<unsigned int>> rec_a, std::pair<unsigned int, std::optional<unsigned int>> rec_b);


  std::vector<std::pair<unsigned int, std::optional <unsigned int>>> adjvec_;

};

} // namespace fixadjacency


#endif  // MKHALAF_LEARNINGCPP17_FIXADJACENCY
