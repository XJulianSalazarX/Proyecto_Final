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
    void start( int );
    int type_obs;

private:

    int getType_obs() const;
    void setType_obs(int value);

public slots:
    void move();


private:
    QTimer *timer;
};

#endif // OBS_H
