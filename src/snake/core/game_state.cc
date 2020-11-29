#include <snake/core/game_state.h>

bool GameState::is_game_over() { return game_over; }

bool GameState::is_apple_eaten() { return is_apple_exists ? false : true; }

int GameState::get_score() { return score; }

void GameState::mark_apple_exists() { is_apple_exists = true; }

void GameState::mark_apple_eaten() {
  is_apple_exists = false;
  update_score();
}

void GameState::mark_as_game_over() { game_over = true; }

void GameState::update_score() {
  if (is_apple_eaten()) score++;
}
