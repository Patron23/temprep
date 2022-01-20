#ifndef MWINDOW_H
#define MWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class mWindow; }
QT_END_NAMESPACE

class mWindow : public QMainWindow
{
    Q_OBJECT

public:
    mWindow(QWidget *parent = nullptr);
    ~mWindow();

private:
    Ui::mWindow *ui;
};
#endif // MWINDOW_H
