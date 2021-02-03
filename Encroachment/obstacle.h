/**
  @file obstacle.h
  @title Class Obstacle
  @brief Hereda QObject y QGraphicsPixmapItem de la librereria de Qt creator,
  clase que representa obstaculos con las cuales player (instancia de la clase
  Character.h) puede chocar.
  */
#ifndef OBS_H
#define OBS_H


#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

class Obstacle: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    /**
     * @brief Obstacle, constructor de la clase obstacle.h
     * @param posx, posción ene le eje x donde aparece el enemigo en scene
     (instancia de la clase QGraphicsScene).
     */
    Obstacle(int posx);
    /**
     * @brief ~Obstacle, destructor de la clase obstacle.h.
     */
    ~Obstacle();
    /**
     * @brief start, comprueba si type_obs es 1 o otro número, si es uno
     el obstaculo representa un tronco, de lo contrario representa una piedra.
     */
    void start();
    /**
     * @brief getType_obs
     * @return un entero que es el valor de type_obs
     */
    int getType_obs() const;

protected:
    /**
     * @brief type_obs, elige un numero aleatorio entre 1 y 2 para asignarle una
      imagen a la clase obstacle.h.
     */
    int type_obs;
    /**
     * @brief timer, se conecta con el metodo move de la clase obstacle.h.
     */
    QTimer *timer;

public slots:
    /**
     * @brief move,comprueba las colisiones de esta clase con la clase Bullet;
     comprueba si en scene (instancia de la clase QGraphicsScene)
     la posición en y(), de este objeto es mayor a la  posición y() de player
     (instancia de la clase character.h), en tal caso de que sea así, esta clase
      es removida de la escena y eliminada de la memoria, ejecuntando el destructor.
     */
    void move();
};

#endif // OBS_H
