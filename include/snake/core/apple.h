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
