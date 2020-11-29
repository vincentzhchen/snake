// Snake console game.
// Copyright (C) 2020  Vincent Chen

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <snake/core/board.h>

#include <iostream>

/**
 * Construct a board on instantiation.
 */
Board::Board(int h, int w, GameState *s) {
  height = h;
  width = w;
  state = s;
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
void Board::update_snake_position(Snake *snake_inst) {
  // put new position
  std::vector<int> snake_pos_x = snake_inst->get_snake_pos_x();
  std::vector<int> snake_pos_y = snake_inst->get_snake_pos_y();
  int snake_len = snake_inst->get_snake_length();

  int head_x = snake_inst->get_snake_head_x();
  int head_y = snake_inst->get_snake_head_y();

  if (board[head_y][head_x] != ' ') {
    state->mark_apple_eaten();
    snake_inst->add_length();
  }

  for (int i = 0; i < snake_len; i++) {
    int x = snake_pos_x[i];
    int y = snake_pos_y[i];
    board[y][x] = snake_inst->get_tail_char();
  }

  board[head_y][head_x] = snake_inst->get_head_char();
}

/**
 * Place an apple at a valid location.
 */
void Board::update_apple_position(Apple *apple_inst) {
  set_board(empty_board);  // copy empty board
  // if apple is not eaten, no update necessary, use current position
  if (!state->is_apple_eaten()) {
    int x = apple_inst->get_apple_pos_x();
    int y = apple_inst->get_apple_pos_y();
    board[y][x] = apple_inst->get_apple_char();

  } else {
    // if apple is eaten, get position of new apple
    bool is_placed = false;
    while (!is_placed) {
      // while apple is not placed, get new apple position and attempt to place
      int x = apple_inst->get_new_apple_pos_x(get_board_width());
      int y = apple_inst->get_new_apple_pos_y(get_board_height());

      if (board[y][x] == ' ') board[y][x] = apple_inst->get_apple_char();
      is_placed = true;
    }

    state->mark_apple_exists();
  }
}

/**
 * Prints map to console.
 */
void Board::draw() {
  system("clear");
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      std::cout << board[i][j];
    }
    std::cout << std::endl;
  }
}
