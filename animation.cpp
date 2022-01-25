#include "animation.h"
#include <algorithm>

bool NameCompare(QString name, QString target)
{
    if (name == target)
        return true;
    return false;
}

Animation::Animation()
{
    InitVars();
}

Animation::Animation(std::vector<Image> _collection)
{
    collection = _collection;

    BasicFrames();
}

void Animation::InitVars()
{
   nextAnimationID = -1;
   frameSize = -1;
   frameStep = -1;
   animationType = -1;
}

void Animation::BasicFrames()
{
    frameSize = 3;
    frame = 1;
    frameStep = 1;
    animationType = 0;
}

// Добавить элемент в коллекцию.
// Возвращает false если элемент равен nullptr
bool Animation::AddToCollection(Image *_img)
{
    if (_img == nullptr)
        return false;

    collection.push_back(*_img);

    return true;
}

bool Animation::RemoveFromCollection(unsigned int id)
{
    if (collection.size() < id)
        return false;

    collection.erase(collection.begin() + id);

    return true;
}

bool Animation::RemoveFromCollection(QString imgName)
{
    unsigned int deleteID = 0;
    bool deleteFlag = false;

    for (unsigned int i = 0; i < collection.size(); i++)
    {
        if (imgName == collection[i].GetName())
        {
            deleteFlag = true;
            deleteID = i;
        }
    }

    if (deleteFlag == true)
    {
       collection.erase(collection.begin() + deleteID);
       return true;
    }
    return false;
}

void Animation::RemoveNextAnimation()
{
    nextAnimationID = -1;
}

void Animation::SetAnimationType(int _set)
{
    animationType = _set;
}

QString Animation::GetName()
{
    return name;
}

void Animation::SetName(QString _name)
{
    name = _name;
}

int Animation::GetFrameStep()
{
    return frameStep;
}

void Animation::SetFrameStep(int _step)
{
    frameStep = _step;
}

int Animation::GetFrameSize()
{
    return frameSize;
}

void Animation::SetFrameSize(int _size)
{
    frameSize = _size;
}

void Animation::SetFrame(int _set)
{
    frame = _set;

    if (frame == 0)
        frame = 1;
}

int Animation::GetFrame()
{
    return frame;
}

int Animation::GetAnimationType()
{
    return animationType;
}

Image& Animation::GetCurrentImage()
{
    unsigned int imgID = frame / frameSize;

    if (imgID > collection.size() - 1)
        throw;

    return collection[imgID];
}

void Animation::SetFrameOptions(int _step, int _size, int _frame)
{
    SetFrameStep(_step);
    SetFrameSize(_size);
    SetFrame(_frame);
}

void Animation::FrameTick(int _tick)
{
    frame += _tick;
}

void Animation::FrameTick()
{
    frame += frameStep;

    if (frame > frameSize*collection.size())
    {
        SwapNext();
    }
}

void Animation::SwapNext()
{
    //LoadFromPool(nextAnimationID);

    // get current frame animation

    //int frameAnimation = frame / frameSize;



    //this->frame         = nextAnimation->frame;
    //this->frameSize     = nextAnimation->frameSize;
    //this->frameStep     = nextAnimation->frameStep;
    //this->animationType = nextAnimation->animationType;
    //this->name          = nextAnimation->name;
    //this->collection    = nextAnimation->collection;
    //this->nextAnimation = nextAnimation->nextAnimation;
}

int Animation::GetNextAnimation()
{
    return nextAnimationID;
}

void Animation::SetNextAnimation(int _next)
{
    nextAnimationID = _next;
}

void Animation::SetAnimationOptions(int _type, int _next)
{
    SetAnimationType(_type);
    SetNextAnimation(_next);
}

