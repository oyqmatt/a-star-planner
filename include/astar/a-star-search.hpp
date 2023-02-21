#ifndef ASTAR_A_STAR_SEARCH_HPP
#define ASTAR_A_STAR_SEARCH_HPP

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
  cv::Mat* graph_;
  Position start_;
  Position goal_;
  Path path_;
};

#endif /* ASTAR_A_STAR_SEARCH_HPP */
