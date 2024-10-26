#include "snake.h"

void SnakeGame::printField(GameInfo_t *game) {
  system("clear");

  for (int i = 0; i < Rows; i++) {
    for (int j = 0; j < Cols; j++) {
      if (apple.first == i && apple.second == j) {
        std::cout << "o";
      }

      bool isBool = false;
      for (auto seg : snake) {
        if (i == seg.first && j == seg.second) {
          std::cout << "1";
          isBool = true;
          break;
        }
      }

      if (!isBool) {
        if (i == apple.first && j == apple.second) {
          continue;
        }
        std::cout << '.';
      }
    }
    std::cout << std::endl;
  }
}

int main() {
  SnakeGame game{20, 10};
  GameInfo_t field;
  game.initGame(&field);

  while (true)
  {
    game.printField(&field);
    game.input(&field);
    usleep(5000);

    if (field.gameOver) {
      break;
    }
  }
  // game.initSnake(10, 5);
  return 0;
}
