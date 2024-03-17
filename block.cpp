#include "block.h"

Block::Block() {
  cellSize = 30;
  rotationState = 0;
  colors = GetCellColors();
  rowOffset = 0;
  colOffset = 0;
}

void Block::Draw() {
  std::vector<Position> tiles = GetCellPositions();
  const int cellSizePlus = cellSize + 1;
  const int cellSizeMinus = cellSize - 1;
  for (Position item : tiles) {
    DrawRectangle(item.GetCol() * cellSizePlus, item.GetRow() * cellSizePlus,
                  cellSizeMinus, cellSizeMinus, colors[id]);
  }
}

void Block::Move(int rows, int cols) {
  rowOffset += rows;
  colOffset += cols;
}

std::vector<Position> Block::GetCellPositions() {
  std::vector<Position> tiles = cells[rotationState];
  std::vector<Position> movedTiles;

  for (Position item : tiles) {
    Position newPos =
        Position(item.GetRow() + rowOffset, item.GetCol() + colOffset);
    movedTiles.push_back(newPos);
  }
  return movedTiles;
}
