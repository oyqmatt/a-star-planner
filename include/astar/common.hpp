#ifndef ASTAR_COMMON_HPP
#define ASTAR_COMMON_HPP

#include <stdint.h>
#include <ostream>
#include <vector>

struct Position {
  int x = 0, y = 0;
  Position();
  Position(int x, int y);

  Position operator+(const Position& a) const;
  bool operator<(const Position& a) const;
  bool operator==(const Position& a) const;
  bool operator!=(const Position& a) const;

  friend std::ostream& operator << (std::ostream &os, const Position &p);
};

struct Node {
  Position position, parent;
  // double cost;
  bool visited;
};

struct Checked {
  Position parent;
  double cost;

  Checked();
  Checked(Position parent, double cost);
};

typedef std::vector<Position> Path;

namespace std {
/* implement hash function so we can put Position into an unordered_set */
template <> struct hash<Position> {
  std::size_t operator()(const Position& id) const noexcept {
      return std::hash<int>()(id.x ^ (id.y << 16));
  }
};
}

#endif /* ASTAR_COMMON_HPP */
