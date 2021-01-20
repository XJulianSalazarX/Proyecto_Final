#include "widget.h"
#include "menu.h"
#include "level1.h"
#include "login.h"

#include <QApplication>

Menu *menu;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Widget w;
//    w.show();
//    menu =  new Menu();
//    menu->show();
    Login *login;
    login = new Login();
    login->show();
    return a.exec();
}
