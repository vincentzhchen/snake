#pragma once

class Apple {
 public:
  Apple(int x, int y);  // constructor
  int get_apple_pos_x();
  int get_apple_pos_y();
  int get_new_apple_pos_x(int board_width);
  int get_new_apple_pos_y(int board_height);

  // apple shape
  char get_apple_char();

 private:
  int apple_pos_x;
  int apple_pos_y;

  // apple shape
  char apple_char = 'A';

  int generate_pos(int l, int u);
};
