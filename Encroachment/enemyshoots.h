#ifndef ENEMYSHOOTS_H
#define ENEMYSHOOTS_H

#include "enemy.h"
#include "enemybullet.h"

class EnemyShoots: public Enemy
{
    Q_OBJECT
public:
    EnemyShoots();
    ~EnemyShoots();

private:
    QTimer *t_shot;
    EnemyBullet *bullet;


public slots:
    void Shot();
};

#endif // ENEMYSHOOTS_H
