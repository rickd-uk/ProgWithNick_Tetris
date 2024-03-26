#pragma once
#include <raylib.h>

#include <vector>

class Grid {
public:
  Grid();
  void Initialize();
  void Print();
  void Draw();
  bool IsCellOutside(int row, int col);
  int GetNumCols() { return numCols; }
  int GetNumRows() { return numRows; }
  bool IsCellEmpty(int row, int col);
  int ClearFullRows();
  int grid[20][10];

private:
  bool IsRowFull(int row);
  void ClearRow(int row);
  void MoveRowDown(int row, int NumRows);
  int numRows;
  int numCols;
  int cellSize;
  std::vector<Color> colors;
};

