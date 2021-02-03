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
    /**
     * @brief health, vida de la clase character.h.
     */
    /**
     * @brief speed, velocidad de la clase character.h.
     */
    double health, speed;
    /**
     * @brief w, ancho de la clase character.h.
     */
    /**
     * @brief h, altura de la clase character.h.
     */
    /**
     * @brief col, se utiliza en el medoto actualize para generar el sprite de la clase character.h.
     */
    double w,h,col;
    /**
     * @brief min, determinar el limite minimo en x de la clase character.h.
     */
    /**
     * @brief max, determinar el limite maximo en x de la clase character.h.
     */
    /**
     * @brief last, ancho de la imagen del atributo pixmap de la clase character.h.
     */
    int min, max, last;
    /**
     * @brief pixmap, toma el path de la imagen para la clase character.h.
     */
    QPixmap *pixmap;
    /**
      * @brief timer, se conecta con el metodo actualize de la clase character.h.
      */
    QTimer *timer;
    /**
     * @brief timerM, si el parametro boss del constructor de la clase character.h
      es verdadero se conecta con el metodo end, si es falso se conecta con el metodo Move.
      de la clase character.h.
     */
    QTimer *timerM;
    /**
     * @brief timerS, se conecta con el metodo shoot de la clase character.h.
     */
    QTimer *timerS;
    /**
     * @brief timerMove, se conecta con el metodo slow de la clase character.h.
     */
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
