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

#include <snake/util/movement.h>

bool Movement::is_up() { return get_direction() == dirns::Direction::UP; }
bool Movement::is_down() { return get_direction() == dirns::Direction::DOWN; }
bool Movement::is_left() { return get_direction() == dirns::Direction::LEFT; }
bool Movement::is_right() { return get_direction() == dirns::Direction::RIGHT; }

void Movement::update_direction() {
  enable_raw_mode();
  dirns::Direction d;
  if (kbhit()) {
    switch (getch()) {
      case 'w':
        d = dirns::Direction::UP;
        break;
      case 's':
        d = dirns::Direction::DOWN;
        break;
      case 'a':
        d = dirns::Direction::LEFT;
        break;
      case 'd':
        d = dirns::Direction::RIGHT;
        break;
    }
  } else {
    d = dirns::Direction::NONE;
  }
  disable_raw_mode();

  if (d != dirns::Direction::NONE) curr_direction = d;
}

dirns::Direction Movement::get_direction() { return curr_direction; }
