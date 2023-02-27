#include "astar/common.hpp"

Position::Position() : x(0), y(0){};
Position::Position(uint16_t x, uint16_t y) : x(x), y(y){};

Position Position::operator+(const Position& a) const {
  return Position(a.x + x, a.y + y);
}

bool Position::operator<(const Position& a) const {
  return (x < a.x && y < a.y);
}