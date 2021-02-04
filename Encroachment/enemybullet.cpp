#include "enemybullet.h"
#include "menu.h"
#include <QDebug>

extern Menu *menu;

EnemyBullet::EnemyBullet()
{
    setPixmap(QPixmap(":/images/bala.png").scaled(10,20));
    setRotation(180);

    disconnect(timer,SIGNAL(timeout()),this,SLOT(move()));
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(12);
}

void EnemyBullet::move()
{
    //mover la bala hacia arriba
    setPos(x(),y()+7);
    //eliminar la bala
    if(menu->getMult()){
        if(pos().y() > menu->multiplayer->playerPos()+100){
            scene()->removeItem(this);
            qDebug() << "Bala enemiga eliminada";
            delete this;
        }
    }
    else{
        if(pos().y() > menu->level1->playerPos()+100){
            scene()->removeItem(this);
            qDebug() << "Bala enemiga eliminada";
            delete this;
        }
    }
}
