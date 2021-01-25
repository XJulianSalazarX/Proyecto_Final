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
    Portal(QObject *parent = nullptr);
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
    void actualize();
    void shoot();
};

#endif // PORTAL_H
