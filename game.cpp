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
