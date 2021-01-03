#ifndef BONUS_H
#define BONUS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>

class Bonus: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bonus();
    ~Bonus();

private:
    QTimer *timer;

public slots:
    void Move();
};

#endif // BONUS_H
