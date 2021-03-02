#include "game_level.h"
 
#include <fstream>
#include <sstream>

#include <map>

#include "common.h"
#include "math.h"
#include<string.h>

void GameLevel::Load(const char *file)
{
    // Очистка старых данных
    this->Bricks.clear();
    
    // Загрузка из файла
    char tileCode;
    GameLevel level;
    std::string line;
    std::ifstream fstream(file);
    std::vector<std::vector<char>> tileData;
    if (fstream)
    {
        while (std::getline(fstream, line)) // построчное чтение файла уровня
        {
            std::istringstream sstream(line);
            std::vector<char> row;
            while (sstream >> tileCode){ // чтение каждого элемента уровня, разделенного пробелом
                std::cout << tileCode;
                row.push_back(tileCode);
            }
            tileData.push_back(row);
        }
        if (tileData.size() > 0)
            this->init(tileData);
    }
}
 
void GameLevel::Draw(Image &screen)
{
    for (GameObject &tile : this->Bricks)
        tile.Draw(screen);
}
 
 /*
bool GameLevel::IsCompleted()
{
    for (GameObject &tile : this->Bricks)
        if (!tile.IsSolid && !tile.Destroyed)
            return false;
    return true;
}
 */

std::tuple<int, int, int, int, int> GameLevel::CheckCollisions(GameObject::Point player_coords){
    std::vector<GameObject> nears;

    int f_left=0, f_top=0, f_right=0, f_bottom=0;
    int f_inclusive = 0;

    for (GameObject &tile : this->Bricks){
        if (strcmp(tile.GetType(), "wall") != 0){continue;}

        GameObject::Point coords = tile.GetCoords();

        int x_delta = - (coords.x + Image::tileSize/2) + (player_coords.x + 8);
        int y_delta = - (coords.y + Image::tileSize/2) + (player_coords.y + 8);

        int critical_delta = Image::tileSize/2;

        std::cout << x_delta << "  " << y_delta << "  "; 

        if (abs(x_delta) >= abs(y_delta)){
            if ((0 <= x_delta) && (x_delta <= critical_delta) && (abs(y_delta) <= critical_delta))
            {
                f_left += 1; std::cout <<"f_left"; 
            }
            if ((0 >= x_delta) && (x_delta >= (-1)*critical_delta) && (abs(y_delta) <= critical_delta))
            {
                f_right += 1; std::cout <<"f_right"; 
            }
        }

        if (abs(x_delta) <= abs(y_delta)){
            if ((abs(x_delta) <= critical_delta) && ((0 >= y_delta) && (y_delta >= (-1)*critical_delta)))
            {
                f_top += 1; std::cout <<"f_top"; 
            }
            
            if ((abs(x_delta) <= critical_delta) && (0 <= y_delta) && (y_delta <= critical_delta))
            {
                f_bottom += 1; std::cout <<"f_bottom"; 
            }
        }
        
        if (abs(x_delta) == abs(y_delta) && abs(y_delta) <= Image::tileSize/2){
            f_inclusive = 1; std::cout <<"f_inclusive"; 
        }

std::cout << std::endl; 
    }

    return {f_left, f_top, f_right, f_bottom, f_inclusive};
}

void GameLevel::init(std::vector<std::vector<char>> tileData)
{
    // Вычисляем размеры
    int height = 8;
    int width = 24; // обратите внимание, что мы можем индексировать вектор, начиная с 0, поскольку данная функция вызывается только в том случае, если height > 0

    GameObject::Point tileCoords;
 
    // Инициализация уровня данными из tileData		
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {   
            tileCoords = {.x = Image::tileSize *x, .y = Image::tileSize  * (y)};
            GameObject obj(tileCoords);

            std::cout<< "tile" << (tileData[y][x]) << std::endl;
            switch (tileData[y][x])
            {
            case '.':
                obj.SetTexture(ResourceManager::GetTexture("floor"));
                obj.SetType("floor");
                break;
            case '#':
                obj.SetTexture(ResourceManager::GetTexture("wall"));
                obj.SetType("wall");
                break;
        
            }

            this->Bricks.push_back(obj);
        }
    }
}