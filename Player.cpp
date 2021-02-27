#include "Player.h"


bool Player::Moved() const
{
  if(coords.x == old_coords.x && coords.y == old_coords.y)
    return false;
  else
    return true;
}

void Player::ProcessInput(MovementDir dir)
{
  int move_dist = move_speed * 1;
  switch(dir)
  {
    case MovementDir::UP:
      if (!std::get<1>(blocked_directions)){
        old_coords.y = coords.y;
        coords.y += move_dist;
      }
      break;
    case MovementDir::DOWN:
      if (!std::get<3>(blocked_directions)){
        old_coords.y = coords.y;
        coords.y -= move_dist;
      }
      break;
    case MovementDir::LEFT:
      if (!std::get<0>(blocked_directions)){
        old_coords.x = coords.x;
        coords.x -= move_dist;
      }
      break;
    case MovementDir::RIGHT:
      if (!std::get<2>(blocked_directions)){
        old_coords.x = coords.x;
        coords.x += move_dist;
      }
      break;
    default:
      break;
  }
}

void Player::Draw(Image &screen)
{ 
  Image::Pixel pix_buf;

  if(Moved())
  {
    old_coords = coords;
  }

  for(int y = coords.y; y < coords.y + height; ++y)
  {
    for(int x = coords.x; x < coords.x + width; ++x)
    { 
      pix_buf = Player::GetPixel(x-coords.x, height-1 - (y-coords.y));

      if (pix_buf.a != 0){
      screen.PutPixel(x, y, pix_buf);
      }
    }
  }
  Image::Pixel d{100, 0, 0, 0};
  screen.PutPixel(coords.x+8, coords.y+8, d);
}