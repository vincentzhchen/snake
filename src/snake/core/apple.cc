#include <snake/core/apple.h>

#include <random>

int Apple::get_apple_pos_x(int board_height) {
  return generate_pos(0, board_height - 2);
}

int Apple::get_apple_pos_y(int board_width) {
  return generate_pos(0, board_width - 2);
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
