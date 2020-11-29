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
    empty_board.push_back(row);
  }
  set_board(empty_board);
}

/**
 * Use this to help reset the board every time snake / apple is updated.
 */
void Board::set_board(std::vector<std::vector<char>> b) { board = b; }

int Board::get_board_height() { return height; }

int Board::get_board_width() { return width; }

/**
 * Snake instance knows how to construct the right coordinates.  Board
 * instance should only be concerned about placing the snake.
 */
void Board::update_snake_position(Snake snake_inst) {
  set_board(empty_board);  // copy empty board

  // put new position
  int *snake_pos_x = snake_inst.get_snake_pos_x();
  int *snake_pos_y = snake_inst.get_snake_pos_y();
  int snake_len = snake_inst.get_snake_length();

  int head_x = snake_pos_x[0];
  int head_y = snake_pos_y[0];

  board[head_y][head_x] = snake_inst.get_head_char();
  for (int i = 1; i < snake_len; i++) {
    int x = snake_pos_x[i];
    int y = snake_pos_y[i];

    board[x][y] = snake_inst.get_tail_char();
  }
}

/**
 * Place an apple at a valid location.
 */
void Board::update_apple_position(Apple &apple_inst) {
  // if apple is not eaten, no update necessary

  bool is_placed = false;
  while (!is_placed) {
    // while apple is not placed, get new apple position and attempt to place
    int x = apple_inst.get_apple_pos_x(get_board_width());
    int y = apple_inst.get_apple_pos_y(get_board_height());

    if (board[y][x] == ' ') board[y][x] = apple_inst.get_apple_char();
    is_placed = true;
  }
}

/**
 * Prints map to console.
 */
void Board::draw() {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      std::cout << board[i][j];
    }
    std::cout << std::endl;
  }
}
