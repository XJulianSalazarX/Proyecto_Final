#include "enemy.h"

Enemy::Enemy()
{
    setPixmap(QPixmap(":/images/carrito_malo.png"));

    int random = 190 +rand() % 800;
    setPos(random,0);

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

Enemy::~Enemy()
{
    delete timer;
}
