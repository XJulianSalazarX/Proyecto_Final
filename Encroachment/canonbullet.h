/**
  @file canonbullet.h
  @title Class Bullet
  @brief Hereda QObject y QGraphicsPixmapItem de la librereria de Qt creator,
  clase que representan balas de cañon.
  */
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
    /**
     * @brief CanonBullet, constructor de la clase canonbullet.h.
     * @param Vo_, representa la velocidad inical con la que es disparada la bala.
     * @param Xo_, representa la posición inicial de la bala en el eje x.
     * @param Yo_, representa la posición inicial de la bala en el eje y.
     */
    CanonBullet(double Vo_,double Xo_,double Yo_);
    /**
      * @brief ~CanonBullet, destructor de la clase canonbullet.h.
      */
    ~CanonBullet();

private:
    /**
     * @brief angle, angulo de la clase canonbullet.h.
     */
    int angle;
    /**
     * @brief time, tiempo de la clase canonbullet.h.
     */
    double time;
    /**
     * @brief Vo, velocidad inicial de la clase canonbullet.h.
     */
    /**
     * @brief Xo, posicion inicial en x de la clase canonbullet.h.
     */
    /**
     * @brief Yo, posicion inicial en y de la clase canonbullet.h.
     */
    /**
     * @brief posx, posicion en x que va tomando la clase a medida que time avanza.
     */
    /**
     * @brief posy,posicion en y que va tomando la clase a medida que time avanza.
     */
    /**
     * @brief g, gravedad de la clase canonbullet.h.
     */
    double Vo,Xo,Yo,posx,posy,g;
    /**
     * @brief timer, se conecta con el metodo Move de la clase canonbullet.h.
     */
    QTimer *timer;

public slots:
    /**
     * @brief Move, mueve la bala por scene (instancia de la clase QGraphicsScene)
     usando las ecuaciones del movimiento parabólico.
     */
    void Move();
};

#endif // CANONBULLET_H
