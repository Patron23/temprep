#include "mwindow.h"
#include <QApplication>
//#include <freeglut-3.2.1\include\GL\glut.h>

#include <animation.h>
#include <image.h>
#include <gameobject.h>
#include <algorithm>
#include <functional>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mWindow w;

    Animation an;
    Animation an2;
    Image imgTempRun1("t", "r1");
    Image imgTempRun2("t", "r2");
    Image imgTempRun3("t", "r3");

    Image imgTempStay1("t", "s1");
    Image imgTempStay2("t", "s2");
    Image imgTempStay3("t", "s3");
    Image JustImageJpg("t", "s5");

    an.AddToCollection(&imgTempRun1);
    an.AddToCollection(&imgTempRun2);
    an.AddToCollection(&imgTempRun3);
    an.SetAnimationOptions(0, 1);
    an.SetFrameOptions(1, 6, 0);
    an.AddToPool();

    an2.AddToCollection(&imgTempStay1);
    an2.AddToCollection(&imgTempStay2);
    an2.AddToCollection(&imgTempStay3);
    an2.SetAnimationOptions(1, 0);
    an2.SetFrameOptions(1, 6, 0);
    an2.AddToPool();

    std::vector <GameObject*> coll;
    coll.push_back(GameObjectCreator().CreateGameObject(an, Position(1, 1)));
    coll.push_back(GameObjectCreator().CreateGameObject(an2, Position(2, 2)));
    coll.push_back(GameObjectCreator().CreateGameObject(JustImageJpg, Position(3, 3)));

    while (true)
    {
        for (unsigned int i = 0; i < coll.size(); i++)
        {
            coll[i]->Tick();
            Image img = coll[i]->GetImage();
        }
    }


    w.show();
    return a.exec();
}
