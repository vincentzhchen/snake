#pragma once

class Snake {
 public:
  Snake(int x, int y);  // constructor
  void move_up(int board_height);
  void move_down(int board_height);
  void move_left(int board_width);
  void move_right(int board_width);

  int *get_snake_pos_x();
  int *get_snake_pos_y();
  int get_snake_length();

  // snake shape
  char get_head_char();
  char get_tail_char();

 private:
  int head_x;
  int head_y;
  // TODO: set config for max tail length
  int snake_pos_x[100];
  int snake_pos_y[100];
  int snake_length = 0;

  // snake shape
  char head_char = 'O';
  char tail_char = 'o';

  void update_position();
};
