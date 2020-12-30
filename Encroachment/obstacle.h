#ifndef OBS_H
#define OBS_H


#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>

class obstacle: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    obstacle();
    ~obstacle();

public slots:
    void move();

private:
    QTimer *timer;
};

#endif // OBS_H
