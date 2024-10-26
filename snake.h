#ifndef CPP_SNAKE_H
#define CPP_SNAKE_H

#include <iostream>
#include <vector>
#include <ctime>
#include <unistd.h>

typedef enum {
    Start,
    Pause,
    Terminate,
    Left,
    Right,
    Up,
    Down,
    Action
} UserAction_t;

typedef struct {
    int **field;
    int score;
    int high_score;
    int level;
    int speed;
    int pause;
    bool gameOver;
} GameInfo_t;
class SnakeGame {
  private:
  std::vector<std::pair<int, int>> snake;
  std::pair<int, int> apple;
  UserAction_t action;
  GameInfo_t *game;
  int headSnakeX;
  int headSnakeY;
  int Rows;
  int Cols;

  public:
  SnakeGame(int x, int y);
  ~SnakeGame();

  void initSnake(int x, int y);
  void initGame(GameInfo_t *game);
  void cordinatApple();
  void input(GameInfo_t *game);
  void checkActions(UserAction_t newAction);
  void moveSnake(UserAction_t action);
  void printField(GameInfo_t *game);
};
#endif
