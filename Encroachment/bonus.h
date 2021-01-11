#ifndef BONUS_H
#define BONUS_H

#include <QObject>
//#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QTimer>
#include <QGraphicsScene>

class Bonus: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Bonus(QObject *parent = nullptr);
    ~Bonus();

    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);


private:
    double w,h,col;
    QPixmap *pixmap;
    QTimer *timer;
    QTimer *timerM;

public slots:
    void Move();
    void actualize();
};

#endif // BONUS_H
