#include "enemyshoots.h"
#include <menu.h>
#include <QDebug>

extern Menu *menu;

EnemyShoots::EnemyShoots(int posx): Enemy(posx)
{
    short random = 1 + rand()%(4-1);
    if(random == 1)
        pixmap->load(":/images/tank1.png");
    else if(random == 2)
        pixmap->load(":/images/tank2.png");
    else
        pixmap->load(":/images/tank3.png");
    //pixmap = new QPixmap(":/images/tank1.png");
    timerS = new QTimer();

    col = 0;
    w = 80;
    h = 92;

    timerD = new QTimer();
    connect(timerD,SIGNAL(timeout()),this,SLOT(Dead()));
    timerD->start(50);

    disconnect(timer,SIGNAL(timeout()),this,SLOT(actualize()));
    connect(timer,SIGNAL(timeout()),this,SLOT(actualize()));
    timer->start(500);

    timerS = new QTimer();
    connect(timerS,SIGNAL(timeout()),this,SLOT(Shoot()));
    timerS->start(2000);

    timerM->start(750);

    health = 2;
}

EnemyShoots::~EnemyShoots()
{
    delete timerS;
    delete timerD;
    delete pixmap;
}

void EnemyShoots::Shoot()
{
    if(y()>=100){
        bullet = new EnemyBullet();
        bullet->setPos(x(),y()+50);
        scene()->addItem(bullet);
    }

}

void EnemyShoots::actualize()
{
    col += 80;
    if(col >= 130){
        col = 0;
    }

    this->update(-w/2,-h/2,w,h);
}

void EnemyShoots::Dead()
{
    QList<QGraphicsItem *> collisions = collidingItems();
    for(QGraphicsItem *i : collisions){
        if(i->collidesWithItem(this)){
            if(typeid(*(i))==typeid (Bullet)){
                scene()->removeItem(i);
                delete i;
                health --;
                if(health == 0){
                    menu->level1->playerScore(5);
                    scene()->removeItem(this);
                    delete this;
                    return;
                }
            }
        }
    }
}
