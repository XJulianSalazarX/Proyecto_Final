#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
//#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QTimer>
#include <QGraphicsScene>
#include "bullet.h"

class Enemy: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Enemy(QObject *parent = nullptr);
    ~Enemy();

    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);

protected:
    double w,h,col;
    QPixmap *pixmap;
    QTimer *timer;
    QTimer *timerM;
    double health;

public slots:
    void actualize();
    void Move();

};

#endif // ENEMY_H
