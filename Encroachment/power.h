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

private:
    double radio,posx,posy;
    int angle,x,y;
    QTimer *timerCircular;

public slots:
    void Circular();
};

#endif // POWER_H
