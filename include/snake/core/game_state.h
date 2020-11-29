#pragma once

class GameState {
 public:
  bool is_game_over();
  bool is_apple_eaten();
  int get_score();
  void mark_apple_exists();
  void mark_apple_eaten();
  void mark_as_game_over();

 private:
  bool game_over = false;
  int score = 0;
  bool is_apple_exists = false;

  void update_score();
};
