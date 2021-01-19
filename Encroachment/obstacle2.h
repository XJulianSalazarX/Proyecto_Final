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

public slots:
    void move();
};

#endif // OBSTACLE2_H
