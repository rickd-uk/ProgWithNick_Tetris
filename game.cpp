#include "game.h"
#include <random>

Game::Game() {
  grid = Grid();
  blocks = GetAllBlocks();
  curBlock = GetRandomBlock();
  nxtBlock = GetRandomBlock();
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
  }
}

void Game::MoveBlockLeft() {
  curBlock.Move(0, -1);
  if (IsBlockOutside()) {
    curBlock.Move(0, 1);
  }
}

void Game::MoveBlockRight() {
  curBlock.Move(0, 1);
  if (IsBlockOutside()) {
    curBlock.Move(0, -1);
  }
}

void Game::MoveBlockDown() {
  curBlock.Move(1, 0);
  if (IsBlockOutside()) {
    curBlock.Move(-1, 0);
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
