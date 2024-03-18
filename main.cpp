#include "game.h"
#include <raylib.h>

int main(void) {
  InitWindow(300, 600, "Tetris");
  Color darkBlue = {44, 44, 127, 255};

  SetTargetFPS(60);
  Game game = Game();

  while (!WindowShouldClose()) {
    game.HandleInput();

    BeginDrawing();
    ClearBackground(darkBlue);

    game.Draw();
    EndDrawing();
  }

  CloseWindow();
}

// 54:00
