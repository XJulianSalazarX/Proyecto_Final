/**
  @file portal.h
  @title Class Portal
  @brief Hereda QObject y QGraphicsItem de la librereria de Qt creator,
  esta clase representa un portal por el cual se generan instancias de la clase
  CanonBullet.
  */
#ifndef PORTAL_H
#define PORTAL_H

#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <canonbullet.h>

class Portal:public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    /**
     * @brief Portal, constructor de la clase portal.h.
     * @param parent
     */
    Portal(QObject *parent = nullptr);
    /**
     * @brief ~Portal, destructor de la clase portal.h.
     */
    ~Portal();
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);

private:
    /**
     * @brief w, ancho de la clase portal.h.
     */
    /**
     * @brief h, altura de la clase portal.h.
     */
    /**
     * @brief col, se utiliza en el medoto actualize para generar el sprite de la clase portal.h.
     */
    /**
     * @brief speed, velocidad de la clase portal.h.
     */
    double w,h,col,speed;
    /**
     * @brief give, aumenta y disminuye la velocidad del atributo speed de la clase portal.h.
     */
    short give;
    /**
     * @brief pixmap, oma el path de la imagen para la clase portal.h.
     */
    QPixmap *pixmap;
    /**
     * @brief timer, se conecta con el metodo actualize de la clase portal.h.
     */
    QTimer *timer;
    /**
     * @brief timerS, se conecta con el metodo shoot de la clase portal.h.
     */
    QTimer *timerS;
    /**
     * @brief bullet, instancia de la clase CanonBullet.
     */
    CanonBullet *bullet;

public slots:
    /**
     * @brief actualize, se usa para generar el sprite de la clase portal.h.
     */
    void actualize();
    /**
     * @brief shoot, genera instancias de la clase CanonBullet.
     */
    void shoot();
};

#endif // PORTAL_H
