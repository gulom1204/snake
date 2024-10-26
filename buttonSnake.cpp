#include "snake.h"

void SnakeGame::input(GameInfo_t *game) {
  char input;
  std::cin >> input;

  switch (input)
  {
  case 'a':
    checkActions(Left);
    break;
  case 'd':
    checkActions(Right);
    break;
  case 'w':
    checkActions(Up);
    break;
  case 's':
    checkActions(Down);
    break;
  default:
    break;
  }
  moveSnake(action);
}

void SnakeGame::checkActions(UserAction_t newAction) {
  if (newAction == Left && action != Right) {
    action = Left;
  }
  else if(newAction == Right && action != Left) {
    action = Right;
  }
  else if (newAction == Up && action != Down) {
    action = Up;
  }
  else if (newAction == Down && action != Up) {
    action = Down;
  }
}

void SnakeGame::moveSnake(UserAction_t action) {
  auto head = snake.front();

  if (action == Left) {
    --head.second;
  }
  else if (action == Right) {
    ++head.second;
  }
  else if (action == Up) {
    --head.first;
  }
  else if (action == Down) {
    ++head.first;
  }

  if (head.second < 1 || head.first == Rows - 1 || head.first < 1 || head.second == Cols - 1) {
    game->gameOver = true;
  }

  for (auto segment : snake) {
    if (head.first == segment.first && head.second == segment.second) {
      game->gameOver = true;
    }
  }

  // cordinatApple();
  if (head.first == apple.first && head.second == apple.second) {
    snake.insert(snake.begin(), head);
    cordinatApple();
  }
  else {
    snake.insert(snake.begin(), head);
    snake.pop_back();
  }
}
