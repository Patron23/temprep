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

    bool LoadImage(std::string _path);
    QImage* GetImage();

private:
    QImage* value;
};

#endif // IMAGE_H
