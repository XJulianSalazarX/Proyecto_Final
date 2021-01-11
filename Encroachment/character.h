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
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
//#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "bullet.h"

class Character:public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    /**
     * @brief Constructor de la clase Character
     */
    Character(QObject *parent = nullptr);
    /**
     * @brief keyPressEvent Mover la clase Character o instanciar la clase Bullet
     * dependiendo de la tecla ingresada
     * @param event Recibe la tecla ingresada por teclado
     */
    void keyPressEvent(QKeyEvent *event);
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);

    double getHealth() const;

private:
    double health, speed;
    double w,h,col;
    QPixmap *pixmap;
    QTimer *timer;
    QTimer *timerM;
    QTimer *timerS;
    QTimer *timerMove;

public slots:
    void actualize();
    void Move();
    void Shoot();
    void Slow();
};

#endif // CHARACTER_H
