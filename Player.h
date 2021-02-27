#ifndef MAIN_PLAYER_H
#define MAIN_PLAYER_H

#include "game_object.h"

#include <tuple>
#include <vector>

enum class MovementDir
{
  UP,
  DOWN,
  LEFT,
  RIGHT
};

class Player : public GameObject
{
public:
  explicit Player(Point pos = {.x = 10, .y = 10}) :
                 GameObject(pos), old_coords(pos) {};

  bool Moved() const;
  void ProcessInput(MovementDir dir);
  void Draw(Image &screen);
  
  std::tuple<int, int, int, int> blocked_directions;

private:
  Point old_coords {.x = 10, .y = 10};
  int move_speed = 6;

};

#endif //MAIN_PLAYER_H
