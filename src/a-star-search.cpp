#include "astar/a-star-search.hpp"

#include "math.h"

#include <iostream>

// AStarSearch::AStarSearch() {
//   // Do nth
// }

AStarSearch::AStarSearch(cv::Mat* graph, Position start, Position goal) {
  graph_ = graph;
  start_ = start;
  goal_ = goal;
  grid_size_ = Position(graph_->size().width, graph_->size().height);
  collate_walls_();
}

void AStarSearch::UpdateGraph(cv::Mat* graph) { graph_ = graph; }

void AStarSearch::UpdateSearch(Position start, Position goal) {
  start_ = start;
  goal_ = goal;
}

/**
 * @brief 
 * 
 * @param start 
 * @param goal 
 * @return Path 
 */
Path AStarSearch::FindPath(Position start, Position goal) {
  open_list_.push(std::make_pair(0.0,start));
  closed_[start] = Checked(start, 0.0);

  while (!open_list_.empty()){
    Position current = open_list_.top().second;
    if (current == goal) {
      while (current != start) {
        path_.push_back(current);
        current = closed_[current].parent;
      }
      path_.push_back(start);
      return path_;
    }
    for (auto neighbour : neighbours(current)) {
      double g = closed_[current].cost + diag_dist_(current,neighbour);
      // double f = g + h;
      // Typically check open list too, but open list is priority queue, hence redundant
      if (closed_.find(neighbour) == closed_.end() || g < closed_[neighbour].cost) {
        closed_[neighbour] = Checked(current,g);
        double h = diag_dist_(neighbour,goal);
        open_list_.push(std::make_pair(g+h, neighbour));
      }
    }
    open_list_.pop();
  }

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
  return neighbours;
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
  for(int i=0; i<graph_->rows; i++)
    for(int j=0; j<graph_->cols; j++){
        // printf("Val: %d\n", graph_->at<u_int8_t>());
      if (graph_->at<uchar>(i,j) < 200) {
        walls_.insert(Position(i,j));
      }
    }
}

double AStarSearch::diag_dist_(Position a, Position b) {
  int dx = abs(a.x - b.x); 
  int dy = abs(a.y - b.y);
  return dx + dy + (SQRT2 -2) * MIN(dx,dy);
}

double AStarSearch::euc_dist_(Position a, Position b) {
  return sqrt((a.x-b.x)^2 + (a.y-b.y)^2);
}