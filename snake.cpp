#include "snake.h"

SnakeGame::SnakeGame(int x, int y) : Rows(x), Cols(y), headSnakeX(x/2), headSnakeY(y/2) {
  srand(static_cast<unsigned>(time(0)));
}

SnakeGame::~SnakeGame() {
  if (game->field)
    for (int i = 0; i < Rows; i++) {
      delete[] game->field[i];
    }
    delete[] game->field;
}

void SnakeGame::initSnake(int x, int y) {
  snake.push_back({x, y});
  // snake.push_back({x - 1, y});
  // snake.push_back({x - 2, y});
  // snake.push_back({x - 3, y});
  snake.shrink_to_fit();
  // for (auto seg : snake) {
  //   std::cout << seg.first << seg.second << std::endl;
  // }
}

void SnakeGame::initGame(GameInfo_t *game) {
  this->game = game;
  game->field = new int * [Rows];
  for (int i = 0; i < Rows; i++) {
    game->field[i] = new int[Cols]();
  }

  for (int i = 0; i < Rows; i++) {
    for (int j = 0; j < Cols; j++) {
      game->field[i][j] = 0;
    }
  }

  initSnake(headSnakeX, headSnakeY);

  cordinatApple();
  game->gameOver = false;
}

void SnakeGame::cordinatApple() {
  int x = rand() % Rows;
  int y = rand() % Cols;

  for (auto segment : snake) {
    if (segment.first == x && segment.second == y) {
      x = rand() % Rows;
      y = rand() % Cols;
    }

  if (x < 1 || x == Rows - 1 || y < 1 || y == Cols - 1) {
    x = rand() % (Rows - 1);
    y = rand() % (Cols - 1);
  }
  }

  apple = {x, y};
}
