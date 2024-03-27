#include "colors.h"
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
  InitWindow(500, 620, "Tetris");
  Color darkBlue = {44, 44, 127, 255};

  Font font = LoadFontEx("font/montserrat.ttf", 55, 0, 0);

  SetTargetFPS(60);
  Game game = Game();

  while (!WindowShouldClose()) {
    game.HandleInput();

    if (EventTriggered(0.2)) {
      game.MoveBlockDown();
    }

    BeginDrawing();
    ClearBackground(darkBlue);

    DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
    DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
    if (game.gameOver) {
      DrawTextEx(font, "GAME OVER", {320, 450}, 25, 2, WHITE);
    }
    DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);
    DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);
    game.Draw();

    EndDrawing();
  }

  CloseWindow();
}

// 54:00
