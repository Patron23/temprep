#ifndef RENDER_H
#define RENDER_H

#include <QString>
#include <QWidget>
#include <QtOpenGLWidgets/QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLContext>

//#include "mwindow.h"
#include "image.h"
#include "gameobject.h"
#include "scene.h"



class DrawHelper
{
public:
    DrawHelper();
    void Paint();

private:
    QBrush background;
    QBrush circleBrush;
    QFont textFont;
};

/* class Render
*   Уровень абстракции над openGL.
*   Все, что связано с openGL - находится только тут.
*/
class Render : public QWidget
{
    Q_OBJECT
public:
    Render(Scene* _Scene);
    virtual ~Render();



private:
    Scene* _scene;
};

#endif // RENDER_H
