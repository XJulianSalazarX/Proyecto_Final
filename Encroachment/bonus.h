/**
  @file bonus.h
  @version 1.0
  @title Class Bonus
  @brief hereda QObject y QGraphicsItem de la librereria de Qt creator, esta clase
  representa una ayuda para aumentar la vida de la chase character.h en caso de
  colisionar.
  */
#ifndef BONUS_H
#define BONUS_H

#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QTimer>
#include <QGraphicsScene>

class Bonus: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    /**
     * @brief Bonus, constructor de la clase bonus.h.
     * @param parent
     */
    Bonus(QObject *parent = nullptr);
    /**
      *@brief ~Bonus, destructor de la clase bonus.h.
      */
    ~Bonus();

    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);

private:
    double w,h,col;
    QPixmap *pixmap;
    QTimer *timer;
    QTimer *timerM;

public slots:
    /**
     * @brief Move, comprueba si en scene (instancia de la clase QGraphicsScene)
     la posición en y(), de este objeto es mayor a la  posición y() de player
     (instancia de la clase character.h), en tal caso de que sea así, esta clase
      es removida de la escena y eliminada de la memoria, ejecuntando el destructor.
     */
    void Move();
    /**
     * @brief actualize, se usa para generar el sprite de la clase bonus.h.
     */
    void actualize();
};

#endif // BONUS_H
