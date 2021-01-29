#ifndef POWER_H
#define POWER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <math.h>

class Power:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Power();
    Power(double amplitude_,double period_, double friction_);

private:
    double radio,posx,posy;
    int angle,x,y;
    QTimer *timer;
    double amplitude,period,friction,time,w;

public slots:
    void Circular();
    void MAS();
};

#endif // POWER_H
