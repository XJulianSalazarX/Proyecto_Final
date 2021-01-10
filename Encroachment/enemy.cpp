#include "enemy.h"
#include <QDebug>
#include "menu.h"

extern Menu *menu;

Enemy::Enemy(QObject *parent):QObject(parent)
{
    //setPixmap(QPixmap(":/images/carrito_malo.png").scaled(50,100));
    pixmap = new QPixmap(":/images/spider.png");

    col=0;
    w = 62.2;
    h = 43;

    int random = 190 +rand() % (800-190);
    setPos(random,menu->level1->playerPos()-720);

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(actualize()));
    timer->start(20);

    timerM = new QTimer();
    connect(timerM,SIGNAL(timeout()),this,SLOT(Move()));
    timerM->start(50);
}

Enemy::~Enemy()
{
    delete timerM;
}

QRectF Enemy::boundingRect() const
{
    return QRectF(-w/2,-h/2,w,h);
}

void Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    option = nullptr;
    widget = nullptr;
    painter->drawPixmap(-w/2,-h/2,*pixmap,col,0,w,h);
}

void Enemy::actualize()
{
    col += 62.2;
    if(col >= 622){
        col = 0;
    }

    this->update(-w/2,-h/2,w,h);
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

    setPos(x(),y()+5);

    if(pos().y() > menu->level1->playerPos()+100){
        scene()->removeItem(this);
        delete this;
        qDebug() << "Enemigo eliminado";
    }

}
