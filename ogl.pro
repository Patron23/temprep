QT       += core gui \
            opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# $$PWD - поиск в каталоге, где .pro file
#INCLUDEPATH += $$PWD/freeglut-3.2.1

SOURCES += \
    animation.cpp \
    engine.cpp \
    gameobject.cpp \
    image.cpp \
    main.cpp \
    mwindow.cpp \
    render.cpp \
    resources.cpp \
    scene.cpp \
    sceneloader.cpp

HEADERS += \
    animation.h \
    engine.h \
    gameobject.h \
    image.h \
    mwindow.h \
    render.h \
    resources.h \
    scene.h \
    sceneloader.h

FORMS += \
    mwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
