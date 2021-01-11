#include "bullet.h"
#include <QDebug>
#include "menu.h"

extern Menu *menu;

Bullet::Bullet()
{
    setPixmap(QPixmap(":/images/bullet.png").scaled(10,20));

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(15);
}

Bullet::~Bullet()
{
    delete timer;
}

void Bullet::move()
{
    //mover la bala hacia arriba
    setPos(x(),y()-10);
    //eliminar la bala
    if(pos().y() < menu->level1->playerPos()-720){
        scene()->removeItem(this);
        qDebug() << "Bala eliminada";
        delete this;
    }
}
