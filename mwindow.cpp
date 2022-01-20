#include "mwindow.h"
#include "ui_mwindow.h"

mWindow::mWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mWindow)
{
    ui->setupUi(this);
}

mWindow::~mWindow()
{
    delete ui;
}

