#include "scene.h"

Scene::Scene()
{

}


void Scene::GameObjectAdd(GameObject* _obj)
{
    gameObjects.push_back(_obj);
}
