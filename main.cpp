#include "game.h"
#include <raylib.h>

double lastUpdateTime = 0.0f;
bool EventTriggered(double interval) {
  double currentTime = GetTime();
  if (currentTime - lastUpdateTime >= interval) {
    lastUpdateTime = currentTime;
    return true;
  }
  return false;
}

int main(void) {
  InitWindow(300, 600, "Tetris");
  Color darkBlue = {44, 44, 127, 255};

  SetTargetFPS(60);
  Game game = Game();

  while (!WindowShouldClose()) {
    game.HandleInput();

    if (EventTriggered(0.2)) {
      game.MoveBlockDown();
    }

    BeginDrawing();
    ClearBackground(darkBlue);

    game.Draw();
    EndDrawing();
  }

  CloseWindow();
}

// 54:00
