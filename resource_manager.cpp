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
 

Image::Pixel* ResourceManager::loadData(const std::string &a_path, int* width, int* height, int* channels){
    return (Image::Pixel*) stbi_load(a_path.c_str(), width, height, channels, sizeof(Image::Pixel));
}

// Создание экземпляров статических переменных
std::map<std::string, Image::Pixel *> ResourceManager::Textures;
 
Image::Pixel* ResourceManager::LoadTexture(const char *file, std::string name)
{   
    int width, height, channels;
    Textures[name] = loadData(file, &width, &height, &channels);
    
    return Textures[name];
}
 
Image::Pixel* ResourceManager::GetTexture(std::string name)
{
    return Textures[name];
}
 
void ResourceManager::Clear()
{
}
