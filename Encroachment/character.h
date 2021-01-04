/**
  @file Character.h
  @version 1.0
  @date 23/12/2020
  @title Class Character
  @brief CLase que representa un carro que se mueve hacia arriba o abajo de un QGraphicsScene
  dependiendo de las teclas ingresadas
  */
#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "bullet.h"

class Character:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    /**
     * @brief Constructor de la clase Character
     */
    Character();
    /**
     * @brief keyPressEvent Mover la clase Character o instanciar la clase Bullet
     * dependiendo de la tecla ingresada
     * @param event Recibe la tecla ingresada por teclado
     */
    void keyPressEvent(QKeyEvent *event);

private:
    double health;
};

#endif // CHARACTER_H
