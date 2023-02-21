#ifndef ASTAR_COMMON_HPP
#define ASTAR_COMMON_HPP

#include <stdint.h>
#include <vector>

struct Position {
  uint16_t x = 0, y = 0;
  Position();
  Position(uint16_t x, uint16_t y);
};

typedef std::vector<Position> Path;

#endif /* ASTAR_COMMON_HPP */
