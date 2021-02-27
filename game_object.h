#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
 
#include "Image.h"
#include <map>



// Объект, хранящий все состояния, относящиеся к отдельно взятой игровой сущности
class GameObject
{
 public:

    //types declaration
    typedef struct{
      int x;
      int y;
    } Point;

    const std::map<char, const char*> tileToCode = {
        {'#', "floor"},
        {'@', "wall"}
    };



    // Конструкторы
    GameObject(Point pos) : coords(pos) {};

    void LoadTexture(const std::string &a_path);
    void SetTexture(Image::Pixel*);
    void SetType(const char* atype){type = atype;}

    Image::Pixel GetPixel(int x, int y) { return data[width * y + x];}

    Point GetCoords(){return coords;}
    const char* GetType(){return type;}

    // Отрисовка спрайта
    void Draw(Image &screen);

  protected:
    // Состояние объекта
    Point coords; 
    // Текстура
    Image::Pixel color {.r = 255, .g = 255, .b = 0, .a = 255};
    Image::Pixel *data = nullptr;
    // Размеры
    int width = -1;
    int height = -1;
    int channels = 3;

    const char* type;

    size_t size = 0;
};
 
#endif