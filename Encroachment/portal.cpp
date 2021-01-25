#include "portal.h"

Portal::Portal(QObject *parent):QObject(parent)
{
    pixmap = new QPixmap(":/images/portal.png");
    col = 0;
    w = 203;
    h = 150;
    speed = 90;
    give = -5;

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(actualize()));
    timer->start(150);
    timerS = new QTimer();
    connect(timerS,SIGNAL(timeout()),this,SLOT(shoot()));
    timerS->start(750);
}

Portal::~Portal()
{

}

QRectF Portal::boundingRect() const
{
    return QRectF(-w/2,-h/2,w,h);
}

void Portal::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    option = nullptr;
    widget = nullptr;
    painter->drawPixmap(-w/2,-h/2,*pixmap,col,0,w,h);
}

void Portal::actualize()
{
    col += w;
    if(col >= 1624){
        col = 0;
    }

    this->update(-w/2,-h/2,w,h);
}

void Portal::shoot()
{
    bullet = new CanonBullet(speed,50,400);
    scene()->addItem(bullet);
    speed += give;
    if(speed > 90){
        scene()->removeItem(this);
        delete this;
    }
    if(speed < 0){
        give = 5;
        speed = 30;
    }
}

