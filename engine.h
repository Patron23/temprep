#ifndef ENGINE_H
#define ENGINE_H

#include "render.h"
#include "scene.h"

enum presetObject
{
    chest_d_open,
    chest_d_closed,
    chest_d_empty,

    chest_g_open,
    chest_g_closed,
    chest_g_empty,

    player,

    fire_torch
};


class Engine
{
public:
    Engine();
    Engine(QString _path);
    ~Engine();

    void ShowScreen();
    bool LoadObject(Position _coord, presetObject _preset);
    void LoadObject(Position _coord, Animation _anim);
    void LoadObject(Position _coord, Image _img);
    void LoadObject(Position _coord, QString _str);
    bool LoadObject(Position _coord, presetObject _preset, bool _control);

private:
    QString path;
    Scene* scene;
    Render* render;
    GameObjectCreator creator;
    GameObject* Control;
};

#endif // ENGINE_H
