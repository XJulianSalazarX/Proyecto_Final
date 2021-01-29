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

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(Circular()));
    timer->start(17);
}

Power::Power(double amplitude_, double period_, double friction_)
{
    setPixmap(QPixmap(":/images/pendulum.png"));
    amplitude = amplitude_;
    period = period_;
    w = 2*M_PI/period;
    friction = friction_;
    time = 0;

    setPos(640,300);

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(MAS()));
    timer->start(50);
}

void Power::Circular()
{
    angle ++;
    if(angle > 360) angle = 0;
    posx = x+(radio*cos(angle*3.14/180));
    posy = y-(radio*sin(angle*3.14/180));
    setPos(posx,posy);
}

void Power::MAS()
{
    time += 0.05;

      x = amplitude*exp(-friction*time)*cos(w*time);
      //x = amplitude*cos(w*time);
      //qDebug() << x;
      setRotation(x);
}
