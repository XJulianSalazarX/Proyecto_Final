#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "bullet.h"

class Character:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Character();
    void keyPressEvent(QKeyEvent *event);
};

#endif // CHARACTER_H
