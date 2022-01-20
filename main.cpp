#include "mwindow.h"
#include <QApplication>
#include <freeglut-3.2.1/include/GL/glut.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mWindow w;
    w.show();
    return a.exec();
}
