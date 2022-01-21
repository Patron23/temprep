#include "mwindow.h"
#include <QApplication>
//#include <freeglut-3.2.1\include\GL\glut.h>

#include <animation.h>
#include <image.h>
#include <gameobject.h>

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

    an.AddToCollection(&imgTempRun1);
    an.AddToCollection(&imgTempRun2);
    an.AddToCollection(&imgTempRun3);
    an.SetAnimationType(1);
    an.SetNextAnimation(1);
    an.SetFrameSize(3);

    an.AddToPool();

    an2.AddToCollection(&imgTempStay1);
    an2.AddToCollection(&imgTempStay2);
    an2.AddToCollection(&imgTempStay3);
    an2.SetAnimationType(2);
    an2.SetNextAnimation(0);
    an2.SetFrameSize(2);

    an2.AddToPool();

    while (true)
    {
        an.FrameTick();
    }

    w.show();
    return a.exec();
}
