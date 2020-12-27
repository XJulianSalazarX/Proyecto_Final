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
    setPos(x(),y()+10);

    if(pos().y() > 720){
        scene()->removeItem(this);
        delete this;
        qDebug() << "Enemigo eliminado";
    }
}
