#ifndef OBS_H
#define OBS_H


#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

class Obstacle: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Obstacle(int posx);
    ~Obstacle();
    void start();


    int getType_obs() const;

    void stopMove();
    void continueMove();

protected:
    int type_obs;
    QTimer *timer;

public slots:
    void move();
};

#endif // OBS_H
