#include <snake/core/board.h>

#include <iostream>

/**
 * Construct a board on instantiation.
 */
Board::Board(int h, int w) {
  height = h;
  width = w;
  initialize_board(height, width);
}

/**
 * Creates the game map in a matrix (vector of vector).
 */
void Board::initialize_board(int height, int width) {
  for (int i = 0; i < height; i++) {
    std::vector<char> row;
    for (int j = 0; j < width; j++) {
      // top and bottom border
      if ((i == 0) | (i == height - 1)) {
        row.push_back('#');
        continue;
      }

      // middle
      if ((j == 0) | (j == width - 1)) {
        row.push_back('#');
      } else {
        row.push_back(' ');
      }
    }
    board.push_back(row);
  }
}

/**
 * Prints map to console.
 */
void Board::draw_board() {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      std::cout << board[i][j];
    }
    std::cout << std::endl;
  }
}
