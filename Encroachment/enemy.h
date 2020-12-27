#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>


class Enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy();
    ~Enemy();

private:
    QTimer *timer;

public slots:
    void Move();

};

#endif // ENEMY_H
