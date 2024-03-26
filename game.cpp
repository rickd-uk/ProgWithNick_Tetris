#include "game.h"
#include <random>

Game::Game() {
  grid = Grid();
  blocks = GetAllBlocks();
  curBlock = GetRandomBlock();
  nxtBlock = GetRandomBlock();
  gameOver = false;
}

Block Game::GetRandomBlock() {
  if (blocks.empty()) {
    blocks = GetAllBlocks();
  }
  int randIndex = rand() % blocks.size();
  Block block = blocks[randIndex];
  blocks.erase(blocks.begin() + randIndex);
  return block;
}

std::vector<Block> Game::GetAllBlocks() {
  return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::Draw() {
  grid.Draw();
  curBlock.Draw();
}
void Game::HandleInput() {
  int keyPressed = GetKeyPressed();
  if (gameOver && keyPressed != 0) {
    gameOver = false;
    Reset();
  }
  switch (keyPressed) {
  case KEY_LEFT:
    MoveBlockLeft();
    break;
  case KEY_RIGHT:
    MoveBlockRight();
    break;
  case KEY_DOWN:
    MoveBlockDown();
    break;
  case KEY_UP:
    RotateBlock();
    break;
  }
}

void Game::MoveBlockLeft() {
  if (!gameOver) {
    curBlock.Move(0, -1);
    if (IsBlockOutside() || !BlockFits()) {
      curBlock.Move(0, 1);
    }
  }
}

void Game::MoveBlockRight() {
  if (!gameOver) {
    curBlock.Move(0, 1);
    if (IsBlockOutside() || !BlockFits()) {
      curBlock.Move(0, -1);
    }
  }
}

void Game::MoveBlockDown() {
  if (!gameOver) {
    curBlock.Move(1, 0);
    if (IsBlockOutside() || !BlockFits()) {
      curBlock.Move(-1, 0);
      LockBlock();
    }
  }
}

bool Game::IsBlockOutside() {
  std::vector<Position> tiles = curBlock.GetCellPositions();
  for (Position item : tiles) {
    if (grid.IsCellOutside(item.GetRow(), item.GetCol())) {
      return true;
    }
  }
  return false;
}

void Game::RotateBlock() {
  if (!gameOver) {
    curBlock.Rotate();
    if (IsBlockOutside() || !BlockFits()) {
      curBlock.UndoRotation();
    }
  }
}

void Game::LockBlock() {
  std::vector<Position> tiles = curBlock.GetCellPositions();
  for (Position item : tiles) {
    grid.grid[item.GetRow()][item.GetCol()] = curBlock.id;
  }
  curBlock = nxtBlock;
  if (!BlockFits()) {
    gameOver = true;
  }
  nxtBlock = GetRandomBlock();
  grid.ClearFullRows();
}

bool Game::BlockFits() {
  std::vector<Position> tiles = curBlock.GetCellPositions();
  for (Position item : tiles) {
    if (!grid.IsCellEmpty(item.GetRow(), item.GetCol())) {
      return false;
    }
  }
  return true;
}

void Game::Reset() {
  grid.Initialize();
  blocks = GetAllBlocks();
  curBlock = GetRandomBlock();
  nxtBlock = GetRandomBlock();
}
