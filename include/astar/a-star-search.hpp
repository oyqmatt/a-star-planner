#ifndef ASTAR_A_STAR_SEARCH_HPP
#define ASTAR_A_STAR_SEARCH_HPP

#include <unordered_set>

#include "astar/common.hpp"
#include "graph.hpp"

class AStarSearch {
 public:
  AStarSearch();
  AStarSearch(cv::Mat* graph, Position start, Position goal);

  void UpdateGraph(cv::Mat* graph);
  void UpdateSearch(Position start, Position goal);

  Path FindPath();

 private:
  // Functions
  void collate_walls_();
  bool is_passable_(const Position pos);
  std::vector<Position> neighbours(const Position grid_pos);

  // Variables
  cv::Mat* graph_;
  Position grid_size_;
  Position start_;
  Position goal_;
  Path path_;
  std::unordered_set<Position> walls_;

  // Constants
  const double SQRT2 = 1.4142135623731;
  const Position DIRS[8] = {{1, 0},  {1, 1},   {0, 1},  {-1, 1},
                            {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
};

#endif /* ASTAR_A_STAR_SEARCH_HPP */
