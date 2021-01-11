#include "obstacle.h"
#include <QDebug>
#include "menu.h"

extern Menu *menu;

Obstacle::Obstacle()
{


    int obs_random= 140 + rand() % (1000- 140);
    setPos(obs_random,menu->level1->playerPos()-1000);

     type_obs=1+rand()%4;
     setType_obs(type_obs);


    start();

}

Obstacle::~Obstacle()
{
    delete timer;
}



void Obstacle::start()
{
    //type_obs 1=tronco   2=charco    3=viento    4=piedra
        if (type_obs==1) setPixmap(QPixmap(":/images/trunk.png").scaled(150,150));
        else if(type_obs==2)setPixmap(QPixmap(":/images/charco.png").scaled(140,140));
        else if (type_obs==3)setPixmap(QPixmap(":/images/brisa.png"));
        else setPixmap(QPixmap(":/images/piedra.png"));

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

int Obstacle::getType_obs() const
{
    return type_obs;
}

void Obstacle::setType_obs(int value)
{
    type_obs = value;
}


void Obstacle::move()
{
    //eliminar  el obstaculo
    if(pos().y() > menu->level1->playerPos()+100){
        scene()->removeItem(this);
        delete this;
        qDebug() << "obstaculo eliminado";
    }
}
