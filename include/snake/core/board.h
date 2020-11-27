#pragma once

#include <vector>

class Board {
 public:
  Board(int width, int height);  // constructor
  void draw_board();

 private:
  int width;   // nun cols
  int height;  // num rows
  std::vector<std::vector<char>> board;

  void initialize_board(int height, int width);
};
