#include "widget.h"
#include "menu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Widget w;
//    w.show();
    Menu menu;
    menu.show();

    return a.exec();
}
