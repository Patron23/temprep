#include "animation.h"
#include <algorithm>

bool NameCompare(std::string name, std::string target)
{
    if (name == target)
        return true;
    return false;
}

Animation::Animation()
{
    InitVars();
}



void Animation::InitVars()
{
   int nextAnimationID = -1;
   int frameSize = -1;
   int frameStep = -1;
   int animationType = -1;
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

bool Animation::RemoveFromCollection(int id)
{
    if (collection.size() < id)
        return false;

    collection.erase(collection.begin() + id);

    return true;
}

bool Animation::RemoveFromCollection(std::string imgName)
{
    int deleteID = -1;

    for (int i = 0; i < collection.size(); i++)
    {
        if (imgName == collection[i].GetName())
            deleteID = i;
    }

    if (deleteID != -1)
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

std::string Animation::GetName()
{
    return name;
}

void Animation::SetName(std::string _name)
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
    int imgID = this->frame / this->frameSize;

    if ((int)imgID > collection.size() - 1)
        return imgErr;

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
    this->frame += this->frameStep;

    if (this->frame > this->frameSize*this->collection.size())
    {
        SwapNext();
    }
}

void Animation::SwapNext()
{
    LoadFromPool(nextAnimationID);

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

void Animation::AddToPool()
{
    AnimationPool.push_back(*this);
}

bool Animation::RemoveFromPool(int id)
{
    if (AnimationPool.size() < id)
        return false;

    AnimationPool.erase(AnimationPool.begin() + id);

    return true;
}

bool Animation::RemoveFromPool(std::string name)
{
    int deleteID = -1;

    for (int i = 0; i < AnimationPool.size(); i++)
    {
        if (name == AnimationPool[i].GetName())
            deleteID = i;
    }

    if (deleteID != -1)
    {
       AnimationPool.erase(AnimationPool.begin() + deleteID);
       return true;
    }
    return false;
}

bool Animation::LoadFromPool(int id)
{
    //Animation temp = AnimationPool.at(id);
    //this = temp;
    Animation _t = AnimationPool[id];

    this->frame = _t.frame;
    this->animationType = _t.animationType;
    this->collection = _t.collection;
    this->frameSize = _t.frameSize;
    this->frameStep = _t.frameStep;
    this->name = _t.name;
    this->nextAnimationID = _t.nextAnimationID;

    return true;
}

bool Animation::LoadFromPool(std::string _name)
{
    int _ID = -1;

    for (int i = 0; i < AnimationPool.size(); i++)
    {
        if (_name == AnimationPool[i].GetName())
            _ID = i;
    }

    if (_ID != -1)
    {
       return LoadFromPool(_ID);;
    }
    return false;
}
