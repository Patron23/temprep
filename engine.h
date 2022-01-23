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

    void ShowScreen();
    bool LoadObject(Position _coord, presetObject _preset);
    void LoadObject(Position _coord, Animation _anim);
    void LoadObject(Position _coord, Image _img);
    bool LoadObject(Position _coord, presetObject _preset, bool _control);

private:
    Render render;
    Scene scene;
    GameObjectCreator creator;
};

#endif // ENGINE_H
