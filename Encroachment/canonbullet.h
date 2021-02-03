#ifndef CANONBULLET_H
#define CANONBULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <math.h>
#include <QTimer>
#include <QGraphicsScene>

class CanonBullet:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    CanonBullet(double Vo_,double Xo_,double Yo_);
    ~CanonBullet();

private:
    int angle,y;
    double time;
    double Vo,Xo,Yo,posx,posy,g;
    QTimer *timer;

public slots:
    void Move();
};

#endif // CANONBULLET_H
