#include "game.h"
#include <random>

Game::Game() {
  grid = Grid();
  blocks = GetAllBlocks();
  curBlock = GetRandomBlock();
  nxtBlock = GetRandomBlock();
  gameOver = false;
  score = 0;
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
  curBlock.Draw(11, 11);
  switch (nxtBlock.id) {
  case 3:
    nxtBlock.Draw(255, 290);
    break;
  case 4:
    nxtBlock.Draw(255, 280);
    break;
  default:
    nxtBlock.Draw(270, 270);
  }
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
    UpdateScore(0, 1);
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
  int rowsCleared = grid.ClearFullRows();
  UpdateScore(rowsCleared, 0);
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
  score = 0;
}

void Game::UpdateScore(int linesCleared, int moveDownPoints) {
  switch (linesCleared) {
  case 1:
    score += 100;
    break;
  case 2:
    score += 200;
  case 3:
    score += 500;
    break;
  default:
    break;
  }
  score += moveDownPoints;
}
