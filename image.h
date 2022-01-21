#ifndef IMAGE_H
#define IMAGE_H

#include <QImage>
#include <string>
/* class Image
*
*   Базовый графический элемент.
*
*   Конструктор:
*   1. Без параметров
*   2. Путь к изображению (внутри вызывается метод LoadImage)
*   Если создание было завершено неудачей, генерируется исключение.
*
*   bool LoadImage(std::string _path)
*   Загрузить картинку.
*
*   QImage* GetImage()
*   Получить картинку. Возвращает nullptr если картинка не была загружена.
*/
class Image
{
public:
    Image();
    Image(std::string _path);
    Image(std::string _path, std::string name);

    bool LoadImage(std::string _path);
    bool LoadImage();
    QImage* GetImage();


    std::string GetName();
    void        SetName(std::string _name);
    void        SetPath(std::string _path);

private:
    QImage* value;
    std::string path;
    std::string name;
};

#endif // IMAGE_H
