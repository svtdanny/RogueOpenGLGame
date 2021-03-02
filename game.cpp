#include "game.h"

#include "resource_manager.h"
#include "game_level.h"

#include "common.h"
# include "Player.h"


Game::Game(int width, int height)
    : State(GAME_ACTIVE), Keys(), Width(width), Height(height)
{

}

Game::~Game()
{

}

void Game::Init()
{
  // Загрузка текстур
  ResourceManager::LoadTexture("../resources/wall32.png", "wall");
  ResourceManager::LoadTexture("../resources/floor32.png", "floor");

  //ResourceManager::GetTexture("wall");

  Image::Pixel * ss_wall = ResourceManager::GetTexture("wall");
  Image::Pixel * ss_floor = ResourceManager::GetTexture("floor");

  //Загрузка уровней
  GameLevel lvl_one; lvl_one.Load("../resources/levels/one.lvl");

  this->Levels.push_back(lvl_one);

  GameObject::Point starting_pos{.x = 100, .y = 100};
  
  this->player = new Player(starting_pos);

   // Загрузка текстуры player
  (*this->player).LoadTexture("../resources/knight.png");

  this->Level = 0;

  std::cout << "INIT END" << std::endl;
}

void Game::Update(float dt)
{
    (*this->player).blocked_directions = this->Levels[this->Level].CheckCollisions((*this->player).GetCoords());
    
    std::cout << std::get<0>((*player).blocked_directions) << std::get<1>((*player).blocked_directions) << std::get<2>((*player).blocked_directions) << std::get<3>((*this->player).blocked_directions)<< std::get<4>((*this->player).blocked_directions) << std::endl;
}

void Game::ProcessInput(float dt)
{
   
}
 
void Game::Render(Image &screen)
{   
    
    this->Levels[this->Level].Draw(screen);

    (*this->player).Draw(screen);

}