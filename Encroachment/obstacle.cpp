#include "obstacle.h"
#include <QDebug>
#include <QList>


obstacle::obstacle()
{


    int obs_random= 140 + rand() % (1000- 140);
    setPos(obs_random,0);


    setPixmap(QPixmap(":/images/valla.jpg").scaled(100,40));
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(100);
}

obstacle::~obstacle()
{
    delete timer;
}

void obstacle::move()
{
    //mover el obstaculo hacia abajo
    setPos(x(),y()+5);
    //eliminar  el obstaculo
    if(pos().y() > 740){
        scene()->removeItem(this);
        delete this;
        qDebug() << "obstaculo eliminado";
    }
}
