#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
 
#include "Image.h"

struct Point
{
  int x;
  int y;
};

// Объект, хранящий все состояния, относящиеся к отдельно взятой игровой сущности
class GameObject
{
 public:
    // Конструкторы
    GameObject(Point pos) : coords(pos) {};

    void LoadTexture(const std::string &a_path);

    Pixel GetPixel(int x, int y) { return data[width * y + x];}

    // Отрисовка спрайта
    void Draw(Image &screen);

  protected:
    // Состояние объекта
    Point coords; 
    // Текстура
    Pixel color {.r = 255, .g = 255, .b = 0, .a = 255};
    Pixel *data = nullptr;
    // Размеры
    int width = -1;
    int height = -1;
    int channels = 3;

    size_t size = 0;
};
 
#endif