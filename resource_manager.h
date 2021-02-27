#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H
 
#include <map>
#include <string>

#include "Image.h" 

//#include "texture.h"
//#include "shader.h"
 
// Статический одноэлементный класс ResourceManager, содержащий несколько функций для загрузки текстур и шейдеров.
// Каждая загруженная текстура и/или шейдер сохраняются для дальнейшего использования.
// Все функции и ресурсы статичны
class ResourceManager
{
public:
    static Image::Pixel* loadData(const std::string &a_path, int* width, int* height, int* channels);
 
    // Хранилище ресурсов
    static std::map<std::string, Image::Pixel*> Textures;
 
    // Загружаем (и генерируем) текстуру из файла
    static Image::Pixel* LoadTexture(const char *file, std::string name);
 
    // Получаем сохраненную текстуру
    static Image::Pixel* GetTexture(std::string name);
 
    // Корректное освобождение памяти всех загруженных ресурсов
    static void Clear();
private:
    // private-конструктор, т.к. мы не хотим, чтобы создавались реальные объекты менеджера ресурсов. Его члены и функции должны быть общедоступными (статичными)
    ResourceManager() {}

    
};
 
#endif