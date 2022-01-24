#include "image.h"
#include <QDir>


//Image::Image()
//    :value("error.png")
//{
//}

Image::Image(QString _path)
    : value(_path)
{

    path = _path;
}

Image::Image(QString _path, QString _name)
    : value(_path)
{
    SetPath(_path);
    SetName(_name);
}

void Image::SetName(QString _name)
{
    name = _name;
}

void Image::SetPath(QString _path)
{
    path = _path;
}

QString Image::GetName()
{
    return name;
}

bool Image::LoadImage()
{
    // todo: write
    try
    {
        QString v = GetPath();
        if (!value.load(v, nullptr))
        {
            throw;
        }
    }
    catch (...)
    {
        return false;
    }

    return true;
}

bool Image::LoadImage(QString _path)
{
    SetPath(_path);
    return LoadImage();
}

QString Image::GetPath()
{
    return path;
}
