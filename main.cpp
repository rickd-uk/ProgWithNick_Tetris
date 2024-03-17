#include <raylib.h>

#include "blocks.cpp"
#include "grid.h"

int main(void) {
  InitWindow(300, 600, "Tetris");
  Color darkBlue = {44, 44, 127, 255};

  SetTargetFPS(60);

  Grid grid = Grid();

  TBlock block = TBlock();
  block.Move(4, 3);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(darkBlue);

    grid.Draw();
    block.Draw();

    EndDrawing();
  }

  CloseWindow();
}

// 54:00
