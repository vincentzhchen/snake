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
