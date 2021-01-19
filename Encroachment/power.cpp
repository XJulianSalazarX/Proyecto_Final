#include "power.h"

Power::Power()
{
    setPixmap(QPixmap(":/images/metal.png"));
    radio = 200;
    x = 640;
    y = 400;
    angle = 0;
    posx = x+(radio*cos(angle*3.14/180));
    posy = y-(radio*sin(angle*3.14/180));

    setPos(posx,posy);

    timerCircular = new QTimer();
    connect(timerCircular,SIGNAL(timeout()),this,SLOT(Circular()));
    timerCircular->start(17);
}

void Power::Circular()
{
    angle ++;
    if(angle > 360) angle = 0;
    posx = x+(radio*cos(angle*3.14/180));
    posy = y-(radio*sin(angle*3.14/180));
    setPos(posx,posy);
}
