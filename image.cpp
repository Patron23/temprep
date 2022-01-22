#include "image.h"

Image::Image()
{

}

Image::Image(std::string _path)
{
    path = _path;
}

Image::Image(std::string _path, std::string _name)
{
    SetPath(_path);
    SetName(_name);
}

void Image::SetName(std::string _name)
{
    name = _name;
}

void Image::SetPath(std::string _path)
{
    path = _path;
}

std::string Image::GetName()
{
    return name;
}

bool Image::LoadImage()
{
    // todo: write
    return false;
}

bool Image::LoadImage(std::string _path)
{
    SetPath(_path);
    return LoadImage();
}

std::string Image::GetPath()
{
    return path;
}
