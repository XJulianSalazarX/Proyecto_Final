#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include <QObject>
#include <bullet.h>

class EnemyBullet: public Bullet
{
    Q_OBJECT
public:
    EnemyBullet();

public slots:
    void move();
};

#endif // ENEMYBULLET_H
