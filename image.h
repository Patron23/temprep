#ifndef IMAGE_H
#define IMAGE_H

#include <QImage>
#include <QString>
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
*   bool LoadImage(QString _path)
*   Загрузить картинку.
*
*   QImage* GetImage()
*   Получить картинку. Возвращает nullptr если картинка не была загружена.
*/
class Image
{
public:
    //Image();
    Image(QString _path);
    Image(QString _path, QString name);

    bool LoadImage(QString _path);
    bool LoadImage();
    QImage* GetImage();


    QString GetName();
    QString GetPath();
    void        SetName(QString _name);
    void        SetPath(QString _path);

private:
    QImage value;
    QString path;
    QString name;
};

#endif // IMAGE_H
