#include "astar/a-star-search.hpp"

AStarSearch::AStarSearch() {
  // Do nth
}

AStarSearch::AStarSearch(cv::Mat* graph, Position start, Position goal) {
  graph_ = graph;
  start_ = start;
  goal_ = goal;
  grid_size_ = Position(graph_->size().width, graph_->size().height);
}

void AStarSearch::UpdateGraph(cv::Mat* graph) { graph_ = graph; }

void AStarSearch::UpdateSearch(Position start, Position goal) {
  start_ = start;
  goal_ = goal;
}

Path AStarSearch::FindPath() {
  // A star algorithm

  return path_;
}

std::vector<Position> AStarSearch::neighbours(Position grid_pos) {
  std::vector<Position> neighbours;
  for (int8_t i = 0; i < 8; i++) {
    Position next(grid_pos + DIRS[i]);
    if (is_passable_(next) && next < grid_size_) {
      neighbours.push_back(next);
    }
  }
}

/**
 * @brief Check for walls
 *
 * @param pos
 * @return true
 * @return false
 */
bool AStarSearch::is_passable_(const Position pos) {
  return walls_.find(pos) == walls_.end();
}

void AStarSearch::collate_walls_() {
  for(uint16_t i=0; i<graph_->rows; i++)
    for(uint16_t j=0; j<graph_->cols; j++){
      walls_.insert(Position(i,j));
    }
}