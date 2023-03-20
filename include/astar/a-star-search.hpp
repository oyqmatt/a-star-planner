#ifndef ASTAR_A_STAR_SEARCH_HPP
#define ASTAR_A_STAR_SEARCH_HPP

#include <unordered_set>
#include <unordered_map>
#include <queue>

#include "astar/common.hpp"
#include "graph.hpp"

class AStarSearch {
 public:
  AStarSearch();
  AStarSearch(cv::Mat* graph, Position start, Position goal);

  void UpdateGraph(cv::Mat* graph);
  void UpdateSearch(Position start, Position goal);

  Path FindPath(Position start, Position goal);

 private:
  // Functions
  void collate_walls_();
  bool is_passable_(const Position pos);
  std::vector<Position> neighbours(const Position grid_pos);
  double diag_dist_(Position a, Position b);
  double euc_dist_(Position a, Position b);

  // Variables
  cv::Mat* graph_;
  Position grid_size_;
  Position start_;
  Position goal_;
  Path path_;
  std::unordered_set<Position> walls_;
  typedef std::pair<double, Position> PQElement;
  std::priority_queue<PQElement, std::vector<PQElement>, std::greater<PQElement>> open_list_;
//   std::unordered_map<Position,double> cost_;
//   std::unordered_map<Position,Position> parent_;
  std::unordered_map<Position,Checked> closed_;

  // Constants
  const double SQRT2 = 1.4142135623731;
  const Position DIRS[8] = {{1, 0},  {1, 1},   {0, 1},  {-1, 1},
                            {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
};

#endif /* ASTAR_A_STAR_SEARCH_HPP */
