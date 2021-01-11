#include "obstacle2.h"
#include "menu.h"
#include <QDebug>

extern Menu *menu;

Obstacle2::Obstacle2(int posx): Obstacle(posx)
{
    start();

    disconnect(timer,SIGNAL(timeout()),this,SLOT(move()));
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

Obstacle2::~Obstacle2()
{

}

void Obstacle2::start()
{
    if (type_obs==1) setPixmap(QPixmap(":/images/charco.png").scaled(130,130));
    else setPixmap(QPixmap(":/images/brisa.png"));
}

void Obstacle2::move()
{
    //eliminar  el obstaculo
    if(pos().y() > menu->level1->playerPos()+100){
        scene()->removeItem(this);
        delete this;
        qDebug() << "obstaculo2 eliminado";
    }
}
