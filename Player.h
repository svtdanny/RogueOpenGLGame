#ifndef MAIN_PLAYER_H
#define MAIN_PLAYER_H

#include "game_object.h"

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

private:
  Point old_coords {.x = 10, .y = 10};
  int move_speed = 4;

};

#endif //MAIN_PLAYER_H
