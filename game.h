#pragma once

#include "blocks.cpp"
#include "grid.h"

class Game {
public:
  Game();
  Block GetRandomBlock();
  std::vector<Block> GetAllBlocks();
  void Draw();
  void HandleInput();
  void MoveBlockLeft();
  void MoveBlockRight();
  void MoveBlockDown();
  Grid grid;
  bool gameOver;
  int score;

private:
  bool IsBlockOutside();
  void RotateBlock();
  void LockBlock();
  bool BlockFits();
  void Reset();
  void UpdateScore(int linesCleared, int moveDownPoints);
  std::vector<Block> blocks;
  Block curBlock;
  Block nxtBlock;
};
