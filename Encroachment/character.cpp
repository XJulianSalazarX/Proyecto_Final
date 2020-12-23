#include "character.h"

Character::Character()
{
    setPixmap(QPixmap(":/images/carrito_bueno.png"));
}

void Character::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W){
        setPos(x(),y()-5);
    }
    else if(event->key() == Qt::Key_S){
        setPos(x(),y()+5);
    }
    else if(event->key() == Qt::Key_A){
        setPos(x()-5,y());
    }
    else if(event->key() == Qt::Key_D){
        setPos(x()+5,y());
    }
}
