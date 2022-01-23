#include "engine.h"

Engine::Engine()
{
}


bool Engine::LoadObject(Position _coord, presetObject _preset)
{
    switch (_preset)
    {
    case presetObject::chest_d_open:
    {
        LoadObject(_coord, Image("chest_d_open.png"));
        break;
    }
    case presetObject::chest_d_closed:
    {
        LoadObject(_coord, Image("chest_d_closed.png"));
        break;
    }
    case presetObject::chest_d_empty:
    {
        LoadObject(_coord, Image("chest_d_empty.png"));
        break;
    }

    case presetObject::chest_g_open:
    {
        LoadObject(_coord, Image("chest_g_open.png"));
        break;
    }
    case presetObject::chest_g_closed:
    {
        LoadObject(_coord, Image("chest_g_closed.png"));
        break;
    }
    case presetObject::chest_g_empty:
    {
        LoadObject(_coord, Image("chest_g_empty.png"));
        break;
    }

    case presetObject::player:
    {
        LoadObject(_coord, Image("player.png"));
        break;
    }

    case presetObject::fire_torch:
    {
        std::vector<Image> tempImages;
        tempImages.push_back(Image("torch_1.png", "torch_1"));
        tempImages.push_back(Image("torch_2.png", "torch_2"));
        tempImages.push_back(Image("torch_3.png", "torch_3"));
        tempImages.push_back(Image("torch_4.png", "torch_4"));
        tempImages.push_back(Image("torch_5.png", "torch_5"));
        tempImages.push_back(Image("torch_6.png", "torch_6"));
        tempImages.push_back(Image("torch_7.png", "torch_7"));
        tempImages.push_back(Image("torch_8.png", "torch_8"));

        Animation tempAnimation(tempImages);
        LoadObject(_coord, tempAnimation);

        break;
    }

    default:
    {
        return false;
    }
    }

    return true;
}

void Engine::LoadObject(Position _coord, Animation _anim)
{
    GameObject* tempObj = creator.CreateGameObject(_anim, _coord);
    scene.GameObjectAdd(tempObj);
}

void Engine::LoadObject(Position _coord, Image _img)
{
    GameObject* tempObj = creator.CreateGameObject(_img, _coord);
    scene.GameObjectAdd(tempObj);
}
