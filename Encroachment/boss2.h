#ifndef BOSS2_H
#define BOSS2_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <enemybullet.h>
#include <math.h>
#include "portal.h"

class Boss2: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Boss2();
    ~Boss2();

    int getHealth() const;

private:
    int speed,health;
    EnemyBullet *bullet;
    QTimer *timerM;
    QTimer *timerS;
    Portal *portal;

public slots:
    void Move();
    void Shoot();
};

#endif // BOSS2_H
