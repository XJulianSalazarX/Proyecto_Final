/**
  @file bullet.h
  @version 1.0
  @date 23/12/2020
  @title Class Bullet
  @brief CLase que representa una bala
  */
#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>

class Bullet: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    /**
     * @brief Constructor por defecto de la clase Bullet
     */
    Bullet();
    /**
      * @brief Destructor de la clase Bullet
      */
    ~Bullet();

public slots:
    /**
     * @brief move Mover la clase Bullet 5 pixeles hacia arriba
     * atraves de la instancia de la clase QGraphicsScene *Scene,
     * si la clase Bullet sale de la escena es eliminada
     */
    void move();

private:
    QTimer *timer;
};

#endif // BULLET_H
