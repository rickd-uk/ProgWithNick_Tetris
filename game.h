#pragma once

#include "blocks.cpp"
#include "grid.h"

class Game {
public:
  Game();
  Block GetRandomBlock();
  std::vector<Block> GetAllBlocks();
  void Draw();
  Grid grid;

private:
  std::vector<Block> blocks;
  Block curBlock;
  Block nxtBlock;
};
