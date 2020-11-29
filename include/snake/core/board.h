#pragma once

#include <snake/core/apple.h>
#include <snake/core/snake.h>

#include <vector>

class Board {
 public:
  Board(int width, int height);  // constructor
  int get_board_height();
  int get_board_width();
  void update_snake_position(Snake snake_inst);
  void update_apple_position(Apple &apple_inst);
  void draw();

 private:
  int width;   // nun cols
  int height;  // num rows
  std::vector<std::vector<char>> empty_board;
  std::vector<std::vector<char>> board;

  void initialize_board(int height, int width);
  void set_board(std::vector<std::vector<char>> b);
};
