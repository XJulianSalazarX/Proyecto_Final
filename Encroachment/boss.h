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
    Boss(QObject *parent = nullptr);
    ~Boss();

    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);

    int getHealth() const;

private:
    double w,h,col;
    QPixmap *pixmap;
    QTimer *timer;
    QTimer *timerM;
    QTimer *timerS;
    int speed, health;
    EnemyBullet *bullet;

public slots:
    void actualize();
    void Move();
    void Shoot();
};

#endif // BOSS_H
