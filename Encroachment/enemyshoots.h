/**
  @file enemyshoots.h
  @version 1.0
  @title Class EnemyShoots
  @brief Hereda la clase Enemy, esta clase representan enemigos de la clase player
  (instancia de la clase character.h) capaces de disparar.
  */
#ifndef ENEMYSHOOTS_H
#define ENEMYSHOOTS_H

#include "enemy.h"
#include "enemybullet.h"

class EnemyShoots: public Enemy
{
    Q_OBJECT
public:
    /**
     * @brief EnemyShoots, constructor de la clase enemyshoots.h.
     * @param posx, posción ene le eje x donde aparece el enemigo en scene
     (instancia de la clase QGraphicsScene).
     */
    EnemyShoots(int posx);
    /**
     * @brief ~EnemyShoots, destructor de la clase enemyshoots.h.
     */
    ~EnemyShoots();

private:
    QTimer *timerS;
    EnemyBullet *bullet;
    QTimer *timerD;


public slots:
    /**
     * @brief Shoot, genera instancias de la clase enemybullet, y las añade a
     scene (instancia de la clase QGraphicsScene).
     */
    void Shoot();
    /**
     * @brief actualize, se usa para generar el sprite de la clase character.h
     */
    void actualize();
    /**
     * @brief Dead, comprueba colisiones de está clase con la clase bullet.
     */
    void Dead();
};

#endif // ENEMYSHOOTS_H
