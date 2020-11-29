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
  int get_snake_length();
  void add_length();

  // snake shape
  char get_head_char();
  char get_tail_char();

 private:
  int head_x;
  int head_y;
  // TODO: set config for max tail length
  std::vector<int> snake_pos_x;
  std::vector<int> snake_pos_y;
  int snake_length = 0;
  GameState *state;

  // snake shape
  char head_char = 'O';
  char tail_char = 'o';

  void update_position();
  bool is_hit_itself();
};
