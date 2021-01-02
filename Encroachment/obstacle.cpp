#include "obstacle.h"
#include <QDebug>

Obstacle::Obstacle()
{


    int obs_random= 140 + rand() % (1000- 140);
    setPos(obs_random,0);

     type_obs=1+rand()%4;
     setType_obs(type_obs);


    start();

}

Obstacle::~Obstacle()
{
    delete timer;
}



void Obstacle::start()
{

    setPixmap(QPixmap(":/images/Mesa_de_trabajo_1.jpg").scaled(100,40));
    //type_obs 1=valla/madera   2=charco    3=viento    4=chatarra
    //    if (type_obs==1) setPixmap(QPixmap(":/images/valla.jpg").scaled(100,40));
    //    else if(type_obs==2)setPixmap(QPixmap(":/images/charco.jpg").scaled(100,40));
    //    else if (type_obs==3)setPixmap(QPixmap(":/images/viento.jpg").scaled(100,40));
    //    else {
    //       setPixmap(QPixmap(":/images/chatarra.png").scaled(100,40));
    //    }

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

int Obstacle::getType_obs() const
{
    return type_obs;
}

void Obstacle::setType_obs(int value)
{
    type_obs = value;
}


void Obstacle::move()
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
