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
    /**
     * @brief radio, radio de la clase power.h.
     */
    /**
     * @brief posx, posicion en x  a traves del tiempo del metodo Circular de la clase power.h.
     */
    /**
     * @brief posy, posicion en y  a traves del tiempo del metodo Circular de la clase power.h.
     */
    double radio,posx,posy;
    /**
     * @brief angle, angulo del metodo Circular de la clase power.h.
     */
    /**
     * @brief x, posicion inicial en x del metodo Circular de la clase power.h.
     */
    /**
     * @brief y, posicion inicial del en y metodo Circular de la clase power.h.
     */
    int angle,x,y;
    /**
     * @brief timer, se conecta con el metodo Circular(con el constructor por defecto)
      y con la sobrecargar del constuctor se conecta con el metodo MAS de la clase power.h.
     */
    QTimer *timer;
    /**
     * @brief amplitude, amplitud del metodo MAS de la clase power.h.
     */
    /**
     * @brief period, periodo del metodo MAS de la clase power.h.
     */
    /**
     * @brief friction, friccion del metodo MAS de la clase power.h.
     */
    /**
     * @brief time, tiempo del metodo MAS de la clase power.h.
     */
    /**
     * @brief w, velocidad tangencial del metodo MAS de la clase power.h.
     */
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
