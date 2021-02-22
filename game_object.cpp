#include "game_object.h"
#include "common.h"

#include "resource_manager.h"

void GameObject::LoadTexture(const std::string &a_path)
{
    if((data = ResourceManager::loadData(a_path.c_str(), &width, &height, &channels)) != nullptr)
  {
    size = width * height * channels;
  }
  std::cout << "Width: " << width << std::endl;
  std::cout << "Height: " << height << std::endl;
  std::cout << "Channel: " << channels << std::endl;
}

void GameObject::Draw(Image &screen)
{
  for(int y = coords.y; y <= coords.y + tileSize; ++y)
  {
    for(int x = coords.x; x <= coords.x + tileSize; ++x)
    {
      screen.PutPixel(x, y, color);
    }
  }
}