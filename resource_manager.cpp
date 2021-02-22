#include "resource_manager.h"
 /*
#include <iostream>
#include <sstream>
#include <fstream>
 */

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
 

Pixel* ResourceManager::loadData(const std::string &a_path, int* width, int* height, int* channels){
    return (Pixel*)stbi_load(a_path.c_str(), width, height, channels, sizeof(Pixel));
}
/*
// Создание экземпляров статических переменных
std::map<std::string, Texture2D> ResourceManager::Textures;
 
Texture2D ResourceManager::LoadTexture(const char *file, bool alpha, std::string name)
{
    Textures[name] = loadTextureFromFile(file, alpha);
    return Textures[name];
}
 
Texture2D ResourceManager::GetTexture(std::string name)
{
    return Textures[name];
}
 
void ResourceManager::Clear()
{
}
 
Texture2D ResourceManager::loadTextureFromFile(const char *file, bool alpha)
{
    // Создаем объект текстуры
    Texture2D texture;
    if (alpha)
    {
        texture.Internal_Format = GL_RGBA;
        texture.Image_Format = GL_RGBA;
    }
 
    // Загружаем изображение
    int width, height, nrChannels;
    unsigned char* data = stbi_load(file, &width, &height, &nrChannels, 0);
 
    // Теперь генерируем текстуру
    texture.Generate(width, height, data);
 
    stbi_image_free(data);
    return texture;
}
*/