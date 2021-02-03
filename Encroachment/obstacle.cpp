#include "obstacle.h"
#include <QDebug>
#include "menu.h"

extern Menu *menu;

Obstacle::Obstacle(int posx)
{

    setPos(posx,menu->level1->playerPos()-1150);

     type_obs=1+rand()%2;

    start();

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);

}

Obstacle::~Obstacle()
{
    delete timer;
}

void Obstacle::start()
{
        if (type_obs==1) setPixmap(QPixmap(":/images/trunk.png").scaled(130,130));
        else setPixmap(QPixmap(":/images/piedra.png"));
}

int Obstacle::getType_obs() const
{
    return type_obs;
}

void Obstacle::stopMove()
{
    timer->stop();
}

void Obstacle::continueMove()
{
    timer->start();
}

void Obstacle::move()
{
    QList<QGraphicsItem *> collisions = collidingItems();
    for(QGraphicsItem *i : collisions){
        if(i->collidesWithItem(this)){
            if(typeid(*(i))==typeid (Bullet)){
                scene()->removeItem(i);
                delete i;
            }
        }
    }
    //eliminar  el obstaculo
    if(pos().y() > menu->level1->playerPos()+100){
        scene()->removeItem(this);
        delete this;
        qDebug() << "obstaculo eliminado";
    }
}
