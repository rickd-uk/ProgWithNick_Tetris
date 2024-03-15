#include <raylib.h>

#include "grid.h"

int main(void) {
  InitWindow(300, 600, "Tetris");
  Color darkBlue = {44, 44, 127, 255};

  SetTargetFPS(60);

  Grid grid = Grid();
  grid.grid[0][0] = 1;
  grid.grid[3][5] = 2;
  grid.grid[6][2] = 5;
  grid.grid[19][9] = 7;
  grid.Print();

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(darkBlue);

    grid.Draw();
    EndDrawing();
  }

  CloseWindow();
}
