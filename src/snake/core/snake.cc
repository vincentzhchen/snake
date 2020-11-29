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

#include <snake/core/snake.h>

#include <iostream>

Snake::Snake(int x, int y, GameState *s) {
  head_x = x;
  head_y = y;
  state = s;

  update_position();
}

void Snake::move_up(int board_height) {
  head_y--;
  if (head_y <= 0) head_y = board_height - 2;
  if (is_hit_itself())
    state->mark_as_game_over();
  else
    update_position();
}

void Snake::move_down(int board_height) {
  head_y++;
  if (head_y >= board_height - 1) head_y = 1;
  if (is_hit_itself())
    state->mark_as_game_over();
  else
    update_position();
}

void Snake::move_left(int board_width) {
  head_x--;
  if (head_x <= 0) head_x = board_width - 2;
  if (is_hit_itself())
    state->mark_as_game_over();
  else
    update_position();
}

void Snake::move_right(int board_width) {
  head_x++;
  if (head_x >= board_width - 1) head_x = 1;
  if (is_hit_itself())
    state->mark_as_game_over();
  else
    update_position();
}

void Snake::update_position() {
  snake_pos_x.insert(snake_pos_x.begin(), head_x);
  snake_pos_y.insert(snake_pos_y.begin(), head_y);

  // without a copy to limit the size, the vector grows forever
  std::vector<int> tmp_vec;

  tmp_vec =
      std::vector<int>(snake_pos_x.begin(), snake_pos_x.begin() + snake_length);
  snake_pos_x = tmp_vec;

  // without this copy to limit the size, the vector grows forever
  tmp_vec =
      std::vector<int>(snake_pos_y.begin(), snake_pos_y.begin() + snake_length);
  snake_pos_y = tmp_vec;
}

bool Snake::is_hit_itself() {
  for (int i = 0; i < snake_length; i++)
    if (snake_pos_x[i] == head_x && snake_pos_y[i] == head_y) return true;
  return false;
}

std::vector<int> Snake::get_snake_pos_x() { return snake_pos_x; }
std::vector<int> Snake::get_snake_pos_y() { return snake_pos_y; }

int Snake::get_snake_head_x() { return head_x; }
int Snake::get_snake_head_y() { return head_y; }
int Snake::get_snake_length() { return snake_length; }

void Snake::add_length() { snake_length++; }

char Snake::get_head_char() { return head_char; }
char Snake::get_tail_char() { return tail_char; }
