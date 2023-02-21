#include "astar/a-star-search.hpp"

AStarSearch::AStarSearch() {
  // Do nth
}

AStarSearch::AStarSearch(cv::Mat* graph, Position start, Position goal) {
  graph_ = graph;
  start_ = start;
  goal_ = goal;
}

void AStarSearch::UpdateGraph(cv::Mat* graph) { graph_ = graph; }

void AStarSearch::UpdateSearch(Position start, Position goal) {
  start_ = start;
  goal_ = goal;
}

Path AStarSearch::FindPath(){
    // A star algorithm
    
    return path_;
}