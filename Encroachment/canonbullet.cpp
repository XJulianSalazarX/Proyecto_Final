#include "canonbullet.h"

#include <QDebug>

CanonBullet::CanonBullet(double Vo_,double Xo_,double Yo_)
{
    setPixmap(QPixmap(":/images/canonbullet.png"));

    angle = 45;
    g = 9.8;
    Vo = Vo_;
    Xo = Xo_;
    Yo = Yo_;
    posx = Xo;
    posy = 720-Yo;
    time = 0;
    setPos(posx,posy);
    qDebug() << posx << ", " << posy;

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(Move()));
    timer->start(10);
}

CanonBullet::~CanonBullet()
{
    delete timer;
}

void CanonBullet::Move()
{
    time += 0.05;
    double Vx,Vy;
    qDebug() << time;
    Vx = Vo * cos(angle*3.14/180);
    Vy = Vo * sin(angle*3.14/180);
    posx = Xo + Vx * time;
    posy = 720 - (Yo + Vy * time - (0.5*g*time*time));
    qDebug() << (Yo + Vy * time - (0.5*g*time*time));
    qDebug() << posx << ", " << posy;
    setPos(posx,posy);
    if(posy > 720){
        scene()->removeItem(this);
        delete this;
        qDebug() << "Bala de canon eliminada";
        return;
    }
}
