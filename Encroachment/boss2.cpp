#include "boss2.h"
#include "menu.h"

extern Menu *menu;

Boss2::Boss2()
{
    setPixmap(QPixmap(":/images/ufo.png").scaled(159,100));
    this->setPos(540,50);

    health = 100;
    speed = 5;

    timerM = new QTimer();
    connect(timerM,SIGNAL(timeout()),this,SLOT(Move()));
    timerM->start(20);

    timerS = new QTimer();
    connect(timerS,SIGNAL(timeout()),this,SLOT(Shoot()));
    timerS->start(1000);
}

Boss2::~Boss2()
{
  delete timerM;
}

int Boss2::getHealth() const
{
    return health;
}

void Boss2::Move()
{
    QList<QGraphicsItem *> collisions = collidingItems();
    for(QGraphicsItem *i : collisions){
        if(i->collidesWithItem(this)){
            if(typeid(*(i))==typeid (Bullet)){
                scene()->removeItem(i);
                delete i;
                health -= 1.5;
                menu->level1->BossHealth();
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
    setPos(x()+speed,y());
}

void Boss2::Shoot()
{

    bullet = new EnemyBullet();
    bullet->setPos(x()+79.5,y()+100);
    scene()->addItem(bullet);
}
