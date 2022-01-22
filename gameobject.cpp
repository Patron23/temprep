#include "gameobject.h"

// *****************************************************************
// Position

Position::Position(int _x, int _y)
{
    SetX(_x);
    SetY(_y);
}

Position::Position()
{
    SetX(0);
    SetY(0);
}

int Position::GetX() { return x; }
int Position::GetY() { return y; }
void Position::SetX(int _pos) { x = _pos; }
void Position::SetY(int _pos) { y = _pos; }

// *****************************************************************
// GameObject

GameObject::GameObject(ObjectType _type)
{
    type = _type;
}

void GameObject::moveObject(int _x, int _y)
{
    SetX(_x + GetX());
    SetY(_y + GetY());
}

ObjectType GameObject::GetObjectType()
{
    return type;
}

void GameObject::Tick(){}

GameObject::~GameObject() {}

// *****************************************************************
// GameObjectStatic

GameObjectStatic::GameObjectStatic(Image _img, Position _pos)
    :GameObject(ObjectType::STATIC)
{
    imageObject = new Image();

    SetX(_pos.GetX());
    SetY(_pos.GetY());

    imageObject->SetName(_img.GetName());
    imageObject->SetPath(_img.GetPath());
    imageObject->LoadImage();
}

void GameObjectStatic::SetupAnimation(Animation _animation)
{
    imageObject = &_animation.GetCurrentImage();
}

void GameObjectStatic::SetupImage(Image _img)
{
    imageObject = &_img;
}

Image GameObjectStatic::GetImage()
{
    return *imageObject;
}

GameObjectStatic::~GameObjectStatic()
{
    if (imageObject != nullptr)
        delete imageObject;
}

void GameObjectStatic::Tick(){}

// *****************************************************************
// GameObjectAnimated

GameObjectAnimated::GameObjectAnimated(Animation _anim, Position _pos)
    :GameObject(ObjectType::ANIMATED)
{
    animationObject = new Animation();

    SetX(_pos.GetX());
    SetY(_pos.GetY());

    animationObject->SetAnimationOptions(
                _anim.GetAnimationType(),
                _anim.GetNextAnimation());

    animationObject->SetFrameOptions(
                _anim.GetFrameStep(),
                _anim.GetFrameSize(),
                _anim.GetFrame());
}

void GameObjectAnimated::SetupAnimation(Animation _animation)
{
    animationObject->SetAnimationOptions(_animation.GetAnimationType(),
                                         _animation.GetNextAnimation());

    animationObject->SetFrameOptions(_animation.GetFrameStep(),
                                     _animation.GetFrameSize(),
                                     _animation.GetFrame());
}

void GameObjectAnimated::SetupImage(Image _img)
{
    animationObject->SetAnimationOptions(0, 0);
    animationObject->SetFrameOptions(0,0,0);
    Image* temp = new Image();
    temp->SetName(_img.GetName());
    temp->SetPath(_img.GetPath());
    temp->LoadImage();

    animationObject->AddToCollection(temp);
}

Image GameObjectAnimated::GetImage()
{
    return animationObject->GetCurrentImage();
}

void GameObjectAnimated::Tick()
{
    animationObject->FrameTick();
}

// *****************************************************************
// GameObjectCreator

GameObject* GameObjectCreator::CreateGameObject(Animation _anim, Position _pos)
{
    return new GameObjectAnimated(_anim, _pos);
}

GameObject* GameObjectCreator::CreateGameObject(Image _img, Position _pos)
{
    return new GameObjectStatic(_img, _pos);
}

//GameObject* GameObject::CreateObject(ObjectType _type, Animation _anim, int posX, int posY)
//{
//    GameObject *temp = new GameObjectAnimated(_anim, Position(posX, posY));
//    return temp;
//}
