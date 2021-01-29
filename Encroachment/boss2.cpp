#include "boss2.h"
#include "menu.h"

extern Menu *menu;

Boss2::Boss2(bool boss3)
{
    if (!boss3){
        setPixmap(QPixmap(":/images/ufo.png").scaled(159,100));
        this->setPos(540,50);

        health = 100;
        speed = 7;

        timerM = new QTimer();
        connect(timerM,SIGNAL(timeout()),this,SLOT(Move()));
        timerM->start(20);

        timerS = new QTimer();
        connect(timerS,SIGNAL(timeout()),this,SLOT(Shoot()));
        timerS->start(1000);
    }
    else{
        setPixmap(QPixmap(":/images/last2.png").scaled(160,100));
        this->setPos(540,50);

        health = 100;
        speed = 8;

        timerM = new QTimer();
        connect(timerM,SIGNAL(timeout()),this,SLOT(Move2()));
        timerM->start(20);

        timerS = new QTimer();
        connect(timerS,SIGNAL(timeout()),this,SLOT(Shoot()));
        timerS->start(1500);
    }
    other_power = true;
}

Boss2::~Boss2()
{
    delete timerM;
    delete timerS;
}

int Boss2::getHealth() const
{
    return health;
}

void Boss2::stopMove()
{
    timerM->stop();
    timerS->stop();
}

void Boss2::continueMove()
{
    timerM->start();
    timerS->start();
}

void Boss2::Move()
{
    QList<QGraphicsItem *> collisions = collidingItems();
    for(QGraphicsItem *i : collisions){
        if(i->collidesWithItem(this)){
            if(typeid(*(i))==typeid (Bullet)){
                scene()->removeItem(i);
                delete i;
                health -= 1;
                menu->level1->BossHealth();
                if(health == 50){
                    portal = new Portal();
                    portal->setPos(50,350);
                    scene()->addItem(portal);
                }
                if(health <= 25 and other_power){
                    menu->level1->changePower();
                    other_power=false;
                }
                if(health == 0){
                    menu->level1->playerScore(100);
                    menu->level1->complete();
                    scene()->removeItem(this);
                    delete this;
                    return;
                }
            }
        }
    }
    if(x() < menu->level1->playerPosX()){
        speed = 5;
        setPixmap(QPixmap(":/images/ufo.png").scaled(159,100));
    }
    else if(x() > menu->level1->playerPosX()){
        speed = -5;
        setPixmap(QPixmap(":/images/ufo2.png").scaled(159,100));
    }
    if(abs(x()-menu->level1->playerPosX()) > 3)
        setPos(x()+speed,y());
}

void Boss2::Move2()
{
    QList<QGraphicsItem *> collisions = collidingItems();
    for(QGraphicsItem *i : collisions){
        if(i->collidesWithItem(this)){
            if(typeid(*(i))==typeid (Bullet)){
                scene()->removeItem(i);
                delete i;
                health -= 0.5;
                menu->level1->BossHealth();
                if(health == 75 or health == 50){
                    portal = new Portal();
                    portal->setPos(50,350);
                    scene()->addItem(portal);
                }
                if(health <= 25 and other_power){
                    menu->level1->changePower();
                    other_power=false;
                }
                if(health == 0){
                    menu->level1->playerScore(100);
                    menu->level1->complete();
                    scene()->removeItem(this);
                    delete this;
                    return;
                }
            }
        }
    }

    if(x() <= 50){
        speed = 7;
        setPos(x()+speed,y()+30);
        setPixmap(QPixmap(":/images/last2.png").scaled(160,100));
    }
    else if(x() >= 1180){
        speed = -7;
        setPos(x()+speed,y());
        setPixmap(QPixmap(":/images/last.png").scaled(160,100));
    }
    else setPos(x()+speed,y());
}

void Boss2::Shoot()
{

    bullet = new EnemyBullet();
    bullet->setPos(x()+79.5,y()+100);
    scene()->addItem(bullet);
}
