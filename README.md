
Нужно сделать:

Render (ur mingw, не исправил)

Engine.RemoveObject

Управление (+ custom object player)

Сделано:
Image
Animation (но нужно проверить тики)
GameObject


---
На завтра:

Render

https://doc.qt.io/qt-5/qopenglwidget.html

https://forum.qt.io/topic/104527/facing-error-undefined-reference-to-__imp__zn/4


try/catch (особенно места где идет подгрузка изображений/анимации. Сюда же можно сделать вывод QMessageBox)


---

Как запустить:
Создаем экземпляр Engine, в параметры принимает путь до ассетов.

Загружаем объекты через LoadObject()
Есть предварительно известные объекты, например player, chest, torch (является анимированным объектом).
Есть возможность создания кастомных объектов (своя анимация или картинка).

Запускаем игру через Engine.ShowScreen()
