#include "bonus.h"
#include "menu.h"
#include <QDebug>

extern Menu *menu;

Bonus::Bonus(QObject *parent):QObject(parent)
{
    //setPixmap(QPixmap(":/images/play.png").scaled(70,70));

    pixmap = new QPixmap(":/images/box.png");

    col=0;
    w = 84;
    h = 71;

    int random = 190 +rand() % (800-190);
    setPos(random,menu->level1->playerPos()-1000);

    timerM = new QTimer();
    connect(timerM,SIGNAL(timeout()),this,SLOT(Move()));
    timerM->start(50);

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(actualize()));
    timer->start(200);
}

Bonus::~Bonus()
{
    delete timer;
    delete timerM;
    delete pixmap;
}

QRectF Bonus::boundingRect() const
{
    return QRectF(-w/2,-h/2,w,h);
}

void Bonus::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    option = nullptr;
    widget = nullptr;
    painter->drawPixmap(-w/2,-h/2,*pixmap,col,0,w,h);
}

void Bonus::stopMove()
{
    timerM->stop();
}

void Bonus::continueMove()
{
    timerM->start();
}

void Bonus::actualize()
{
    col += 84;
    if(col >= 420){
        col = 0;
    }

    this->update(-w/2,-h/2,w,h);
}

void Bonus::Move()
{
    if(pos().y() > menu->level1->playerPos()+100){
        scene()->removeItem(this);
        delete this;
        qDebug() << "Bonus eliminado";
    }
}
