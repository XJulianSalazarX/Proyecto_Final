#ifndef OBSTACLE2_H
#define OBSTACLE2_H

#include <QObject>
#include "obstacle.h"

class Obstacle2: public Obstacle
{
    Q_OBJECT
public:
    Obstacle2(int posx);
    ~Obstacle2();
    void start();

private:
    QTimer *timerWind;
    short pix;

public slots:
    void move();
    void moveWind();
};

#endif // OBSTACLE2_H
