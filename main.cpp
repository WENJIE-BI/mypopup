#include <QApplication>
#include <QMainWindow>
#include "mypopup.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
#if 0
    Mypopup mp;
//    mp.setGeometry(QRect(300, 300, 200, 350));
    mp.setStartX(300);
    mp.setStartY(280);
    mp.setWidth(200);
    mp.setHeight(350);
    mp.setTriwidth(20);
    mp.setTriheight(20);
#else
    Mypopup *mp = new Mypopup(300, 280, 150, 350, 20, 20, nullptr);
    mp->show();
#endif
    return a.exec();
}
