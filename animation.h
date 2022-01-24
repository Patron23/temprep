#ifndef ANIMATION_H
#define ANIMATION_H

#include "image.h"
#include <vector>

/* class Animation
*   Коллекция картинок.
*
*   Конструктор:
*   1. Без параметров
*   2. Картинка
*   3. Коллекция картинок.
*
*   Frames:
*   Кол-во фреймов вычисляется collection.size()*frameSize
*
*   1. FrameSize
*   Размер одного фрейма (в тиках)
*
*   2. Frame
*   Текущее состояние внутри фрейма.
*
*   После окончания текущей анимации (конец фреймов) происходит следующее:
*   1. Счетчик сбивается до 0 и анимация повторяется.
*   2. Запускается новая анимация, которая указывается в Animation* nextAnimation
*/
class Animation
{
public:
    Animation();
    Animation(Image* _img);
    Animation(std::vector<Image> _collection);

    void InitVars();

    Image& GetCurrentImage();

    bool AddToCollection(Image* _img);
    bool RemoveFromCollection(int id);
    bool RemoveFromCollection(QString imgName);

    void RemoveNextAnimation();
    int  GetNextAnimation();
    void SetNextAnimation(int _next);

    void SetFrame(int _set);
    int GetFrame();

    int  GetFrameSize();
    void SetFrameSize(int _size);

    int  GetAnimationType();
    void SetAnimationType(int _set);
    void SetAnimationOptions(int _type, int _next);

    QString GetName();
    void        SetName(QString _name);

    int  GetFrameStep();
    void SetFrameStep(int _step);
    void SetFrameOptions(int _step, int _size, int _frame = 0);

    void FrameTick(int _tick);
    void FrameTick();

    void GetNextFromList();

private:
    std::vector<Image> collection;
    int nextAnimationID;
    QString name;

    int frameSize;
    int frame;
    int frameStep;
    int animationType;

    void BasicFrames();
    void SwapNext();
};

    //static std::vector<Animation> AnimationPool;
    //static Image imgErr("error.png");

#endif // ANIMATION_H
