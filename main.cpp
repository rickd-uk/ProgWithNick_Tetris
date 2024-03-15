#include <raylib.h>

#include "grid.h"

int main(void) {
  InitWindow(300, 600, "Tetris");
  Color darkBlue = {44, 44, 127, 255};

  SetTargetFPS(60);

  Grid grid = Grid();
  grid.Print();

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(darkBlue);

    grid.Draw();
    EndDrawing();
  }

  CloseWindow();
}
