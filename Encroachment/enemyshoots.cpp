#include "enemyshoots.h"

EnemyShoots::EnemyShoots()
{
    t_shot = new QTimer();
    connect(t_shot,SIGNAL(timeout()),this,SLOT(Shot()));
    t_shot->start(2000);
}

EnemyShoots::~EnemyShoots()
{
    delete t_shot;
}

void EnemyShoots::Shot()
{
    if(y()>=100){
    bullet = new EnemyBullet();
    bullet->setPos(x()+50,y()+200);
    scene()->addItem(bullet);
    }

}
