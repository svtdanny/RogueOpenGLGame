#ifndef GAMELEVEL_H
#define GAMELEVEL_H
#include <vector>
 
#include "game_object.h"
#include "resource_manager.h"

// Класс GameLevel содержит все кирпичи уровней игры, 
// а также функционал для загрузки/рендеринга информации с жесткого диска
class GameLevel
{
public:
    // Состояние уровня
    std::vector<GameObject> Bricks;
 
    // Конструктор
    GameLevel() { }
 
    // Загрузка уровня из файла
    void Load(const char *file);
 
    // Рендеринг уровня
    void Draw(Image &screen);
    
    // Функция для проверки коллизий <left, top, right, bottom>
    std::tuple<int, int, int, int, int> CheckCollisions(GameObject::Point);
    
private:
    // Инициализация уровня данными из tileData
    void init(std::vector<std::vector<char>> tileData);
};
 
#endif