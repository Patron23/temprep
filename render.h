#ifndef RENDER_H
#define RENDER_H

#include "image.h"

/* class Render
*
*   Уровень абстракции над openGL.
*   Все, что связано с openGL - находится только тут.
*/
class Render
{
public:
    Render();

    void InitializeOGLWindow();
    Image LoadImage(std::string _path);
    void DrawImage(Image _image);
};

#endif // RENDER_H
