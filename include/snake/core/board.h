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

#pragma once

#include <snake/core/apple.h>
#include <snake/core/game_state.h>
#include <snake/core/snake.h>

#include <vector>

class Board {
 public:
  Board(int height, int width, GameState *state);  // constructor
  int get_board_height();
  int get_board_width();
  void update_snake_position(Snake *snake_inst);
  void update_apple_position(Apple *apple_inst);
  void draw();

 private:
  int width;   // nun cols
  int height;  // num rows
  std::vector<std::vector<char>> empty_board;
  std::vector<std::vector<char>> board;
  GameState *state;

  void initialize_board(int height, int width);
  void set_board(std::vector<std::vector<char>> b);
};
