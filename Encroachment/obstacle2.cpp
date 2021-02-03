#include "obstacle2.h"
#include "menu.h"
#include <QDebug>

extern Menu *menu;

Obstacle2::Obstacle2(int posx): Obstacle(posx)
{
    pix = 0;
    start();

    disconnect(timer,SIGNAL(timeout()),this,SLOT(move()));
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);

    if (type_obs == 2){
        pix = 5;
        timerWind = new QTimer();
        connect(timerWind,SIGNAL(timeout()),this,SLOT(moveWind()));
        timerWind->start(250);
    }
}

Obstacle2::~Obstacle2()
{
   if(type_obs != 1){
       delete timerWind;
   }
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

void Obstacle2::moveWind()
{
    setPos(x()+pix,y());
    if(pix == 5) pix = -5;
    else pix = 5;
}
