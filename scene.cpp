#include "scene.h"

Scene::Scene()
{

}

Scene::~Scene()
{
    for (auto obj : gameObjects)
    {
        delete obj;
    }
    gameObjects.clear();
}

void Scene::GameObjectAdd(GameObject* _obj)
{
    gameObjects.push_back(_obj);
}

GameObject& Scene::GetLastCreatedObject()
{
    int id = -1;

    if (gameObjects.size() > 0)
        id = gameObjects.size() - 1;
    else
        throw;

    return *gameObjects[id];
}
