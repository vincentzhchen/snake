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

#include <snake/core/game_state.h>

#include <vector>

class Snake {
 public:
  Snake(int x, int y, GameState *state);  // constructor
  void move_up(int board_height);
  void move_down(int board_height);
  void move_left(int board_width);
  void move_right(int board_width);

  std::vector<int> get_snake_pos_x();
  std::vector<int> get_snake_pos_y();
  int get_snake_head_x();
  int get_snake_head_y();
  int get_snake_length();
  void add_length();

  // snake shape
  char get_head_char();
  char get_tail_char();

 private:
  int head_x;
  int head_y;
  std::vector<int> snake_pos_x;
  std::vector<int> snake_pos_y;
  int snake_length = 1;
  GameState *state;

  // snake shape
  char head_char = 'O';
  char tail_char = 'o';

  void update_position();
  bool is_hit_itself();
};
