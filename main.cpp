#include <QApplication>
#include <qlibrary.h>
#include <QDir>

#include <animation.h>
#include <image.h>
#include "engine.h"
#include <gameobject.h>
#include <algorithm>
#include <functional>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Engine engine(QDir::currentPath() + "/debug/");

    engine.LoadObject(Position(0, 0), presetObject::player, true);
    engine.LoadObject(Position(1, 0), presetObject::chest_d_closed);
    engine.LoadObject(Position(1, 3), presetObject::fire_torch);

    engine.ShowScreen();

    return a.exec();
}
