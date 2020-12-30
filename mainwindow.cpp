#include "mainwindow.h"

#include "mypopup.h"

#include "mytriangle.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    Mypopup *my = new Mypopup(this);
    my->setGeometry(QRect(20, 20, 200, 330));
//    my->setStyleSheet("background-color:gray;");
    my->move(0, 0);
}
