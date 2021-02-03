/**
  @file boss2.h
  @version 1.0
  @title Class Boss
  @brief hereda QObject y QGraphicsPixmapItem de la librereria de Qt creator, esta clase
  representa el jefe final a enfrentar player (instancia de la clase character.h) en
  el nivel 2 y 3.
  */
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
    /**
     * @brief Boss2, constructor de la clase boss2.h
     * @param boss3, representa si player (instancia de la clase character.h), se
     enfrenta a boss2.h en el nivel 2 o 3, si boss3 = false, se enfrenta al jefe del
     nivel2, de lo contario, si boss3 = truem se enfrenta al jefe del nivel3.
     */
    Boss2(bool boss3 = false);
    /**
     * @brief ~Boss, destructor de la clase boss.h
     */
    ~Boss2();

    /**
     * @brief getHealth
     * @return  retorna un entero, que es el valor del atributo health, que representa
     la vida de la clase boss2.h
     */
    int getHealth() const;

    /**
     * @brief stopMove, detiene los QTimer´s timerM, timerS.
     */
    void stopMove();
    /**
     * @brief continueMove, inicia los Qtimer´s timerM, timerS.
     */
    void continueMove();

private:
    int speed,health;
    EnemyBullet *bullet;
    QTimer *timerM;
    QTimer *timerS;
    Portal *portal;
    bool other_power;

public slots:
    /**
     * @brief Move, comprueba colisiones de esta clase, con la clase bullet.h, además,
     mueve esta clase, de izquierda a dercha, persiguiendo a player (instancia de la
     clase character.h) en scene (instancia de la clase QGraphicsScene).
     */
    void Move();
    /**
     * @brief Move2, comprueba colisiones de esta clase, con la clase bullet.h, además,
     mueve esta clase, de izquierda a dercha y hacia abajo en scene (instancia de la
     clase QGraphicsScene).
     */
    void Move2();
    /**
     * @brief Shoot, genera instancias de la clase enemybullet, y las añade a
     scene (instancia de la clase QGraphicsScene).
     */
    void Shoot();
};

#endif // BOSS2_H
