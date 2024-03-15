#include <raylib.h>

int main(void) {
  InitWindow(300, 600, "Tetris");

  Color darkBlue = {44, 44, 127, 255};

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(darkBlue);
    EndDrawing();
  }

  CloseWindow();
}
