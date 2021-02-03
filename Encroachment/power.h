/**
  @file power.h
  @title Class Power
  @brief Hereda QObject y QGraphicsPixmapItemItem de la librereria de Qt creator,
  esta clase representan obstaculos contra player (instacia de la clase character)
  al enfrentar a los jefes de los niveles.
  */
#ifndef POWER_H
#define POWER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <math.h>

class Power:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    /**
     * @brief Power, constructor de la clase power.h que realiza un movimiento circular.
     */
    Power();
    /**
     * @brief Power, sobrecar del constructor de la clase power.h que realiza un
     movimiento armonico simple.
     * @param amplitude_, representa la amplitud del movimiento armónico simple.
     * @param period_, representa el periodo del movimiento armónico simple.
     * @param friction_, representa la fricción dada al movimiento armónico simple.
     */
    Power(double amplitude_,double period_, double friction_);
    /**
     * @brief ~Power, destructor de la clase obstacle.h.
     */
    ~Power();

private:
    double radio,posx,posy;
    int angle,x,y;
    QTimer *timer;
    double amplitude,period,friction,time,w;

public slots:
    /**
     * @brief Circular, mueve este objeto por scene (instancia de la clase
     QGraphicsScene) usando las ecuaciones del movimiento circular.
     */
    void Circular();
    /**
     * @brief MAS, mueve este objeto por scene (instancia de la clase
     QGraphicsScene) usando las ecuaciones del movimiento armónico simple.
     */
    void MAS();
};

#endif // POWER_H
