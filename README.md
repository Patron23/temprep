---
Нужно сделать:
Render (ur mingw, не исправил)
Engine.RemoveObject
Управление

---

Как запустить:
Создаем экземпляр Engine, в параметры принимает путь до ассетов.

Загружаем объекты через LoadObject()
Есть предварительно известные объекты, например player, chest, torch (является анимированным объектом).
Есть возможность создания кастомных объектов (своя анимация или картинка).

Запускаем игру через Engine.ShowScreen()
