/**
  @file boss.h
  @version 1.0
  @title Class Boss
  @brief Hereda QObject y QGraphicsItem de la librereria de Qt creator, esta clase
  representa el jefe final a enfrentar player (instancia de la clase character.h) en
  el nivel 1.
  */
#ifndef BOSS_H
#define BOSS_H

#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include "enemybullet.h"

class Boss: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    /**
     * @brief Boss, constructor de la clase boss.h.
     * @param parent
     */
    Boss(QObject *parent = nullptr);
    /**
     * @brief ~Boss, destructor de la clase boss.h.
     */
    ~Boss();

    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);

    /**
     * @brief getHealth
     * @return  retorna un entero, que es el valor del atributo health, que representa
     la vida de la clase boss.h.
     */
    int getHealth() const;

    /**
     * @brief stopMove, detiene los QTimer´s timer, timerM, timerS.
     */
    void stopMove();
    /**
     * @brief continueMove, inicia los Qtimer´s timer,timerM, timerS.
     */
    void continueMove();

private:
    /**
     * @brief w, ancho de la clase boss.h.
     */
    /**
     * @brief h, altura de la clase boss.h.
     */
    /**
     * @brief col, se utiliza en el medoto actualize para generar el sprite de la clase boss.h.
     */
    double w,h,col;
    /**
     * @brief pixmap, toma el path de la imagen para la clase boss.h.
     */
    QPixmap *pixmap;
    /**
     * @brief timer, se conecta con el metodo actualize de la clase boss.h.
     */
    QTimer *timer;
    /**
     * @brief timerM, se conecta con el metodo move de la clase boss.h.
     */
    QTimer *timerM;
    /**
     * @brief timerS, se conecta con el metodo Shoot de la clase boss.h.
     */
    QTimer *timerS;
    /**
     * @brief speed, velocidad de la clase boss.h.
     */
    /**
     * @brief health, vida de la clase boss.h.
     */
    int speed, health;
    /**
     * @brief bullet, instancia de la clase EnemyBullet.h.
     */
    EnemyBullet *bullet;
    /**
     * @brief other_power, si es verdadero y el atributo health es menor que 25,
     llama el metodo changePower de la clase level1.h.
     */
    bool other_power;

public slots:
    /**
     * @brief actualize, se usa para generar el sprite de la clase boss.h.
     */
    void actualize();
    /**
     * @brief Move, comprueba colisiones de esta clase, con la clase bullet.h, además,
     mueve esta clase de izquierda a dercha en scene (instancia de la clase QGraphicsScene).
     */
    void Move();
    /**
     * @brief Shoot, genera instancias de la clase enemybullet.h, y las añade a
     scene (instancia de la clase QGraphicsScene).
     */
    void Shoot();
};

#endif // BOSS_H
