/**
  @file enemybullet.h
  @title Class EnemyBullet
  @brief Hereda la clase bullet; está clase representa las balas disparadas por
  la clase enemy2 (instancia de la clse enmyshoots.h) y boss2 (instancia de la clase
  boss2.h).
  */
#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include <QObject>
#include <bullet.h>

class EnemyBullet: public Bullet
{
    Q_OBJECT
public:
    /**
     * @brief EnemyBullet, constructor de la clase enemybullet.h.
     */
    EnemyBullet();

public slots:
    /**
     * @brief move, mover la clase Bullet 5 pixeles hacia abajo
     atraves de la instancia de la clase QGraphicsScene *Scene,
     si la clase Bullet sale de la escena visible es eliminada de la
     memoria.
     */
    void move();
};

#endif // ENEMYBULLET_H
