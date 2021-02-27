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

void GameObject::SetTexture(Image::Pixel* texture_data){
  data = texture_data;
  height = Image::tileSize;
  width = Image::tileSize;
}

void GameObject::Draw(Image &screen)
{
  for(int y = coords.y; y < coords.y + height; ++y)
  {
    for(int x = coords.x; x < coords.x + width; ++x)
    {
      screen.PutPixel(x, y, GameObject::GetPixel(x-coords.x, height-1 - (y-coords.y)));
    }
  }

  Image::Pixel d{100, 0, 0, 0};
  screen.PutPixel(coords.x+Image::tileSize/2, coords.y+Image::tileSize/2,d );
}