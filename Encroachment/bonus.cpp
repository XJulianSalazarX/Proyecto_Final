#include "bonus.h"
#include <QDebug>

Bonus::Bonus()
{
    setPixmap(QPixmap(":/images/Mesa_de_trabajo_1.jpg").scaled(100,100));

    int random = 190 +rand() % (800-190);
    setPos(random,-200);

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(Move()));
    timer->start(50);
}

Bonus::~Bonus()
{
    delete timer;
}

void Bonus::Move()
{
    setPos(x(),y()+10);

    if(pos().y() > 720){
        scene()->removeItem(this);
        delete this;
        qDebug() << "Bonus eliminado";
    }
}
