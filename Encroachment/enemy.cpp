#include "enemy.h"
#include <QDebug>

Enemy::Enemy()
{
    setPixmap(QPixmap(":/images/carrito_malo.png"));

    int random = 190 +rand() % (800-190);
    setPos(random,-200);

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
            scene()->removeItem(i);
            scene()->removeItem(this);
            delete i;
            delete this;
            return;
        }
    }

    setPos(x(),y()+10);

    if(pos().y() > 720){
        scene()->removeItem(this);
        delete this;
        qDebug() << "Enemigo eliminado";
    }

}
