#include "obstacle.h"
#include <QDebug>
#include <QList>


obstacle::obstacle()
{


    int obs_random= 140 + rand() % (1000- 140);
    setPos(obs_random,0);

     type_obs=1+rand()%4;
     setType_obs(type_obs);


    start();

}

obstacle::~obstacle()
{
    delete timer;
}



void obstacle::start()
{
    //type_obs 1=valla/madera   2=charco    3=viento    4=chatarra

    int a= getType_obs();
    if (a==1) setPixmap(QPixmap(":/images/valla.jpg").scaled(100,40));
    else if(a==2)setPixmap(QPixmap(":/images/charco.jpg").scaled(100,40));
    else if (a==3)setPixmap(QPixmap(":/images/viento.jpg").scaled(100,40));
    else {
       setPixmap(QPixmap(":/images/chatarra.png").scaled(100,40));
    }

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(100);
}

int obstacle::getType_obs() const
{
    return type_obs;
}

void obstacle::setType_obs(int value)
{
    type_obs = value;
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
