/**
  @file character.h
  @version 1.0
  @title Class Character
  @brief Hereda QObject y QGraphicsItem de la librereria de Qt creator,
  clase que representa un carro que se puede mover a la izquieda o
  derecha de un QGraphicsScene dependiendo de las teclas ingresadas.
  */
#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "bullet.h"

class Character: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    /**
     * @brief Character, constructor de la clase character.h.
     */
    Character(bool boss = false,QObject *parent = nullptr);
    /**
     * @brief ~Character, destructor de la clase character.h.
     */
    ~Character();
    /**
     * @brief keyPressEvent Mover la clase Character o instanciar la clase Bullet
     * dependiendo de la tecla ingresada.
     * @param event, tecla pulsada en el teclado.
     */
    void keyPressEvent(QKeyEvent *event);
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);

    /**
     * @brief getHealth
     * @return  retorna un entero, que es el valor del atributo health, que representa
     la vida de la clase character.h.
     */
    double getHealth() const;
    /**
     * @brief stopMove, detiene los QTimer´s timerM, timerS.
     */
    void stopMove();
    /**
     * @brief continueMove, inicia los Qtimer´s timerM, timerS.
     */
    void continueMove();

private:
    double health, speed;
    double w,h,col;
    int min, max, last;
    QPixmap *pixmap;
    QTimer *timer;
    QTimer *timerM;
    QTimer *timerS;
    QTimer *timerMove;

public slots:
    /**
     * @brief actualize, se usa para generar el sprite de la clase character.h.
     */
    void actualize();
    /**
     * @brief Move, comprueba colisiones de esta clase, con la clase enemy.h,
     enemybullet.h, enemyshoots.h, obstacle.h, obstacle2.h y bonus.h, además,
     mueve esta clase, y pixeles hacia el 0 de scene (instancia de la clase
     QGraphicsScene).
     */
    void Move();
    /**
     * @brief Shoot, genera instancias de la clase bullet.h, y las añade a
     scene (instancia de la clase QGraphicsScene).
     */
    void Shoot();
    /**
     * @brief Slow, le asigna un valor de 7.5 a speed, detiene el timer timerMove,
     e inicia el timerS.
     */
    void Slow();
    /**
     * @brief End, comprueba colisiones de esta clase, con la clase enemybullet.h,
     power.h, canonbullet.h y boss2.h.
     */
    void End();
};

#endif // CHARACTER_H
