#include <snake/core/snake.h>

#include <iostream>
Snake::Snake(int x, int y, GameState *s) {
  head_x = x;
  head_y = y;
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
  int prev_x = snake_pos_x[0] = head_x;
  int prev_y = snake_pos_y[0] = head_y;
  int tmp_x, tmp_y;

  for (int i = 1; i < snake_length; i++) {
    tmp_x = snake_pos_x[i];
    tmp_y = snake_pos_y[i];
    snake_pos_x[i] = prev_x;
    snake_pos_y[i] = prev_y;
    prev_x = tmp_x;
    prev_y = tmp_y;
  }
}

bool Snake::is_hit_itself() {
  for (int i = 0; i < snake_length; i++)
    if (snake_pos_x[i] == head_x && snake_pos_y[i] == head_y) return true;
  return false;
}

int *Snake::get_snake_pos_x() { return snake_pos_x; }

int *Snake::get_snake_pos_y() { return snake_pos_y; }

int Snake::get_snake_length() { return snake_length; }

char Snake::get_head_char() { return head_char; }

char Snake::get_tail_char() { return tail_char; }
