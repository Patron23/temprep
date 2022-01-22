#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "image.h"
#include "animation.h"


enum ObjectType
{
    STATIC,
    ANIMATED,
    NOTINIT
};

class Position
{
public:
    Position();
    Position(int _x, int _y);

    int  GetX();
    void SetX(int _pos);

    int GetY();
    void SetY(int _pos);

private:
    int x, y;
};

class GameObject : public Position
{
public:
    GameObject(ObjectType _type);

    virtual ~GameObject();
    virtual Image GetImage() = 0;

    virtual void SetupAnimation(Animation _animation) = 0;
    virtual void SetupImage(Image _img) = 0;
    virtual void Tick();
    ObjectType GetObjectType();
    void moveObject(int _x, int _y);

private:
    ObjectType type;
};

class GameObjectStatic : public GameObject, public Image
{
public:
    GameObjectStatic(Image _img, Position _pos);

    void SetupAnimation(Animation _animation) override;
    void SetupImage(Image _img) override;
    void Tick() override;
    Image GetImage() override;
    ~GameObjectStatic();

    Image* imageObject;
};

class GameObjectAnimated : public GameObject, public Animation
{
public:
    GameObjectAnimated(Animation _anim, Position _pos);

    void SetupAnimation(Animation _animation) override;
    void SetupImage(Image _img) override;
    void Tick() override;
    Image GetImage() override;

    Animation* animationObject;
};

class GameObjectCreator
{
public:

    GameObject* CreateGameObject(Animation _anim, Position _pos);
    GameObject* CreateGameObject(Image _img, Position _pos);
};


#endif // GAMEOBJECT_H
