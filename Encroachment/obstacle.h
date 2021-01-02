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
    Obstacle();
    ~Obstacle();
    void start();


    int getType_obs() const;
    void setType_obs(int value);

private:
    int type_obs;

public slots:
    void move();


private:
    QTimer *timer;
};

#endif // OBS_H
