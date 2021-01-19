#ifndef ENEMYSHOOTS_H
#define ENEMYSHOOTS_H

#include "enemy.h"
#include "enemybullet.h"

class EnemyShoots: public Enemy
{
    Q_OBJECT
public:
    EnemyShoots(int posx);
    ~EnemyShoots();

private:
    QTimer *timerS;
    EnemyBullet *bullet;
    QTimer *timerD;


public slots:
    void Shoot();
    void actualize();
    void Dead();
};

#endif // ENEMYSHOOTS_H
