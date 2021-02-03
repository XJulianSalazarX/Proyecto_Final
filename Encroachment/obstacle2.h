/**
  @file obstacle2.h
  @version 1.0
  @title Class Obstacle2
  @brief Hereda la clase Obstacle, esta clase representa obstaculos con las cuales
  player (instancia de la clase Character.h) al colisionar reducice la velocidad.
  */
#ifndef OBSTACLE2_H
#define OBSTACLE2_H

#include <QObject>
#include "obstacle.h"

class Obstacle2: public Obstacle
{
    Q_OBJECT
public:
    /**
     * @brief Obstacle2, constructor de la clase obstacle2.h
     * @param posx, posción ene le eje x donde aparece el enemigo en scene
     (instancia de la clase QGraphicsScene).
     */
    Obstacle2(int posx);
    /**
     * @brief ~Obstacle2, destructor de la clase obstacle2.h.
     */
    ~Obstacle2();
    /**
     * @brief start, comprueba si type_obs es 1 u otro número, si es uno
     el obstaculo representa un charco, de lo contrario representa viento.
     */
    void start();

private:
    QTimer *timerWind;
    short pix;

public slots:
    /**
     * @brief move, comprueba si en scene (instancia de la clase QGraphicsScene)
     la posición en y(), de este objeto es mayor a la  posición y() de player
     (instancia de la clase character.h), en tal caso de que sea así, esta clase
      es removida de la escena y eliminada de la memoria, ejecuntando el destructor.
     */
    void move();
    /**
     * @brief moveWind, mueve el objeto 5 px a la izquierda y luego 5 a la derecha
     en caso de que la clase obstacle.h represente el viento.
     */
    void moveWind();
};

#endif // OBSTACLE2_H
