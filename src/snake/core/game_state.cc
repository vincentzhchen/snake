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
