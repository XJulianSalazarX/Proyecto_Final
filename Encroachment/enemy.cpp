#include "enemy.h"
#include <QDebug>
#include "menu.h"

extern Menu *menu;

Enemy::Enemy()
{
    setPixmap(QPixmap(":/images/carrito_malo.png").scaled(50,100));

    int random = 190 +rand() % (800-190);
    setPos(random,menu->level1->playerPos()-720);

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(Move()));
    timer->start(50);
}

Enemy::~Enemy()
{
    delete timer;
}

void Enemy::Move()
{
    QList<QGraphicsItem *> collisions = collidingItems();
    for(QGraphicsItem *i : collisions){
        if(i->collidesWithItem(this)){
            if(typeid(*(i))==typeid (Bullet)){
                scene()->removeItem(i);
                scene()->removeItem(this);
                delete i;
                delete this;
                return;
            }
        }
    }

    setPos(x(),y()+10);

    if(pos().y() > menu->level1->playerPos()+100){
        scene()->removeItem(this);
        delete this;
        qDebug() << "Enemigo eliminado";
    }

}
