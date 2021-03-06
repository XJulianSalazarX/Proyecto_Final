#include "boss.h"
#include "menu.h"

extern Menu *menu;

Boss::Boss(QObject *parent):QObject(parent)
{
    pixmap = new QPixmap(":/images/enemy.png");

    col = 0;
    w = 100;
    h = 100;
    speed = 7;
    health = 100;

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(actualize()));
    timer->start(100);

    timerM = new QTimer();
    connect(timerM,SIGNAL(timeout()),this,SLOT(Move()));
    timerM->start(20);

    timerS = new QTimer();
    connect(timerS,SIGNAL(timeout()),this,SLOT(Shoot()));
    timerS->start(1000);

    setPos(540,100);
    other_power = true;
}

Boss::~Boss()
{
    delete pixmap;
    delete timer;
    delete timerM;
    delete timerS;
}

QRectF Boss::boundingRect() const
{
    return QRectF(-w/2,-h/2,w,h);
}

void Boss::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    option = nullptr;
    widget = nullptr;
    painter->drawPixmap(-w/2,-h/2,*pixmap,col,0,w,h);
}

int Boss::getHealth() const
{
    return health;
}

void Boss::stopMove()
{
    timerM->stop();
    timerS->stop();
    timer->stop();
}

void Boss::continueMove()
{
    timerM->start();
    timerS->start();
    timer->start();
}

void Boss::actualize()
{
    col += w;
    if(col >= 1100){
        col = 0;
    }

    this->update(-w/2,-h/2,w,h);
}

void Boss::Move()
{
    //colisiones
    QList<QGraphicsItem *> collisions = collidingItems();
    for(QGraphicsItem *i : collisions){
        if(i->collidesWithItem(this)){
            if(typeid(*(i))==typeid (Bullet)){
                scene()->removeItem(i);
                delete i;
                health -= 1.5;
                if(!menu->getMult()){
                    menu->level1->BossHealth();
                    if(health <= 25 and other_power){
                        menu->level1->changePower();
                        other_power=false;
                    }
                    if(health <= 0){
                        scene()->removeItem(this);
                        delete this;
                        menu->level1->playerScore(100);
                        menu->level1->complete();
                        return;
                    }
                }
                else{
                    menu->multiplayer->BossHealth();
                    if(health <= 25 and other_power){
                        menu->multiplayer->changePower();
                        other_power = false;
                    }
                    if(health <= 0){
                        scene()->removeItem(this);
                        delete this;
                        menu->multiplayer->setBoss_win(false);
                        menu->multiplayer->endTurn();
                        return;
                    }
                }
            }
        }
    }

    //movimiento
    if(x() <= 50) speed = 7;
    else if(x() >= 1180) speed = -7;
    setPos(x()+speed,y());
}

void Boss::Shoot()
{
    bullet = new EnemyBullet();
    bullet->setPos(x(),y()+50);
    scene()->addItem(bullet);
}
