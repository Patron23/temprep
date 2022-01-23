#include "scene.h"

Scene::Scene()
{

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
