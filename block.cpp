#include "block.h"

Block::Block() {
  cellSize = 30;
  rotationState = 0;
  colors = GetCellColors();
}

void Block::Draw() {
  std::vector<Position> tiles = cells[rotationState];
  const int cellSizePlus = cellSize + 1;
  const int cellSizeMinus = cellSize - 1;
  for (Position item : tiles) {
    DrawRectangle(item.getCol() * cellSizePlus, item.getRow() * cellSizePlus,
                  cellSizeMinus, cellSizeMinus, colors[id]);
  }
}
