#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <string>
#include <gameobject.h>

class Scene
{
public:
    Scene();

    void GameObjectAdd(GameObject* _obj);
    void GameObjectRemove(int id);
    void GameObjectsRemove(std::string name);
    void GameObjectRemove(Position frist, Position second);
    GameObject& GetObjectByID(int id);
    GameObject& GetLastCreatedObject();
    void Draw();

private:

    std::vector <GameObject*> gameObjects;

};

#endif // SCENE_H
