#include "widget.h"
#include "login.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login l;
    l.show();
   // Widget w;
   // w.show();

    return a.exec();
}
