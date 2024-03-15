#pragma once
#include <map>
#include <vector>

#include "position.h"

class Block {
 public:
  Block();
  int id;
  std::map<int, std::vector<Position>> cells;

 private:
  int cellSize;
  int rotationState;
};
