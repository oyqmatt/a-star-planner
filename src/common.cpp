#include "astar/common.hpp"

Position::Position() : x(0), y(0){};
Position::Position(int x, int y) : x(x), y(y){};

Position Position::operator+(const Position& a) const {
  return Position(a.x + x, a.y + y);
}
bool Position::operator<(const Position& a) const {
  return (x < a.x || y < a.y);
}
bool Position::operator==(const Position& a) const {
  return (x == a.x && y == a.y);
}
bool Position::operator!=(const Position& a) const {
  return (x != a.x || y != a.y);
}

std::ostream& operator << (std::ostream &os, const Position &p) {
  os << "(" << p.x << ", " << p.y << ")";
  return os;
}

Checked::Checked() : parent(), cost(0) {};
Checked::Checked(Position parent, double cost) : parent(parent), cost(cost){};