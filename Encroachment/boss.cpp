#include "boss.h"

Boss::Boss(QObject *parent):QObject(parent)
{
    pixmap = new QPixmap(":/images/enemy.png");

    col = 0;
    w = 100;
    h = 100;
    speed = 5;

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(actualize()));
    timer->start(100);

    timerM = new QTimer();
    connect(timerM,SIGNAL(timeout()),this,SLOT(Move()));
    timerM->start(18);

    setPos(540,100);
}

Boss::~Boss()
{
    delete pixmap;
    delete timer;
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
    if(x() <= 50) speed = 5;
    else if(x() >= 1180) speed = -5;
    setPos(x()+speed,y());
}
