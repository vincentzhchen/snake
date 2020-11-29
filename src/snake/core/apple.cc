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

#include <snake/core/apple.h>

#include <random>

Apple::Apple(int x, int y) {
  apple_pos_x = x;
  apple_pos_y = y;
}

int Apple::get_apple_pos_x() { return apple_pos_x; }
int Apple::get_apple_pos_y() { return apple_pos_y; }

int Apple::get_new_apple_pos_x(int board_height) {
  apple_pos_x = generate_pos(1, board_height - 2);
  return apple_pos_x;
}
int Apple::get_new_apple_pos_y(int board_width) {
  apple_pos_y = generate_pos(1, board_width - 2);
  return apple_pos_y;
}

char Apple::get_apple_char() { return apple_char; }

/**
 * Generic method to generate random uniform integer.
 */
int Apple::generate_pos(int lower, int upper) {
  std::random_device rand_dev;
  std::mt19937 generator(rand_dev());
  std::uniform_int_distribution<int> uniform(lower, upper);
  return uniform(generator);
}
