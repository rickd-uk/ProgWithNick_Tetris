#pragma once
#include <map>
#include <vector>

#include "colors.h"
#include "position.h"

class Block {
public:
  Block();
  void Draw(int offsetY, int offsetX);
  void Move(int rows, int cols);
  void Center(int yShift = 0, int xShift = 3) { Move(yShift, xShift); }
  std::vector<Position> GetCellPositions();
  void Rotate();
  void UndoRotation();
  int id;
  std::map<int, std::vector<Position>> cells;

private:
  int cellSize;
  int rotationState;
  std::vector<Color> colors;
  int rowOffset;
  int colOffset;
};
