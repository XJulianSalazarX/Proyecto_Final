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
    double w,h,col,speed;
    short give;
    QPixmap *pixmap;
    QTimer *timer;
    QTimer *timerS;
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
