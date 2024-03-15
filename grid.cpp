#include "grid.h"

#include <iostream>

constexpr int OPAQUE = 255;

Grid::Grid() {
  numRows = 20;
  numCols = 10;
  cellSize = 30;
  Initialize();
  colors = GetCellColors();
}

void Grid::Initialize() {
  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numCols; col++) {
      grid[row][col] = 0;
    }
  }
}

void Grid::Print() {
  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numCols; col++) {
      std::cout << grid[row][col] << " ";
    }
    std::cout << std::endl;
  }
}

std::vector<Color> Grid::GetCellColors() {
  Color darkGray = {26, 31, 40, OPAQUE};
  Color green = {47, 230, 23, OPAQUE};
  Color red = {232, 18, 18, OPAQUE};
  Color orange = {236, 116, 17, OPAQUE};
  Color yellow = {237, 234, 4, OPAQUE};
  Color purple = {166, 0, 247, OPAQUE};
  Color cyan = {21, 204, 209, OPAQUE};
  Color blue = {13, 64, 216, OPAQUE};

  return {darkGray, green, red, orange, yellow, purple, cyan, blue};
}

void Grid::Draw() {
  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numCols; col++) {
      int cellValue = grid[row][col];
      DrawRectangle(col * cellSize, row * cellSize, cellSize, cellSize,
                    colors[cellValue]);
    }
  }
}
