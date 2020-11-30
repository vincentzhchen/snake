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
#include <snake/core/board.h>
#include <snake/core/game_state.h>
#include <snake/core/snake.h>
#include <snake/util/movement.h>
#include <unistd.h>

#include <iostream>

int main() {
  // setup
  GameState *state = new GameState();

  Board board_inst(20, 20, state);

  Apple *apple_inst = new Apple(board_inst.get_board_width() / 4,
                                board_inst.get_board_height() / 4);
  board_inst.update_apple_position(apple_inst);

  Snake *snake_inst = new Snake(board_inst.get_board_width() / 2,
                                board_inst.get_board_height() / 2, state);
  board_inst.update_snake_position(snake_inst);

  board_inst.draw();

  Movement move_state;  // controls current direction of movement
  while (!state->is_game_over()) {
    move_state.update_direction();

    if (move_state.is_up()) {
      snake_inst->move_up(board_inst.get_board_height());
    } else if (move_state.is_down()) {
      snake_inst->move_down(board_inst.get_board_height());
    } else if (move_state.is_left()) {
      snake_inst->move_left(board_inst.get_board_width());
    } else if (move_state.is_right()) {
      snake_inst->move_right(board_inst.get_board_width());
    }

    board_inst.update_apple_position(apple_inst);
    board_inst.update_snake_position(snake_inst);
    board_inst.draw();

    std::cout << "SCORE: " << state->get_score() << std::endl;
    usleep(200000);  // this is in microseconds
  }
  return 0;
}
