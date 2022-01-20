#ifndef ANIMATION_H
#define ANIMATION_H

#include "image.h"
#include <vector>

/* class Animation
*
*   Коллекция картинок.
*
*   Конструктор:
*   1. Без параметров
*   2. Картинка
*   3. Коллекция картинок.
*
*   Frames:
*   1. Frame
*   Сколько фреймов у нас имеется.
*
*   2. FrameSize
*   Размер одного фрейма (в тиках)
*
*   3. FramePart
*   Текущее состояние внутри фрейма.
*
*   После окончания текущей анимации (конец фреймов) происходит следующее:
*   1. Счетчик сбивается до 0 и анимация повторяется.
*   2. Запускается новая анимация, которая указывается в Animation* nextAnimation
*
*
*
*/
class Animation
{
public:
    Animation();
    Animation(Image* _img);
    Animation(std::vector<Image> _collection);

    bool AddToCollection(Image* _img);
    bool RemoveFromCollection(int id);
    bool RemoveFromCollection(std::string imgName);

    void RemoveNextAnimation();
    void SetNextAnimation(Animation* _next);

private:
    std::vector<Image> collection;
    Animation* nextAnimation;

};

#endif // ANIMATION_H
