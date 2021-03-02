#ifndef GAME_H
#define GAME_H

#include <vector>

#include "game_level.h"
#include "Player.h"

// Описываем текущее состояние игры
enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};

// Класс Game содержит все связанные с игрой параметры состояния и 
// различный функционал. 

// Он объединяет все игровые данные в один класс, 
// обеспечивая тем самым простой доступ к каждому из компонентов класса и 
// возможность управления ими

class Game
{
public: 
    // Игровое состояние
    GameState State;
    bool Keys[1024];
    int Width, Height;
    
    std::vector<GameLevel> Levels;
    int Level;

    Player* player;

    // Конструктор
    Game(int width, int height);
 
    // Деструктор
    ~Game();
 
    // Инициализация начального состояния игры (загрузка всех шейдеров, текстур, уровней)
    void Init();
 
    // Игровой цикл
    void ProcessInput(float dt);
    void Update(float dt);
    void Render(Image &screen);
};

#endif