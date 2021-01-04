#include "enemybullet.h"
#include <QDebug>

EnemyBullet::EnemyBullet()
{
    setRotation(180);

    disconnect(timer,SIGNAL(timeout()),this,SLOT(move()));
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void EnemyBullet::move()
{
    //mover la bala hacia arriba
    setPos(x(),y()+20);
    //eliminar la bala
    if(pos().y() > 720){
        scene()->removeItem(this);
        qDebug() << "Bala enemiga eliminada";
        delete this;
    }
}
