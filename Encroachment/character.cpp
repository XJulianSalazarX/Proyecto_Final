#include "character.h"

Character::Character()
{
    setPixmap(QPixmap(":/images/carrito_bueno.png"));

    health = 100;
}

void Character::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W and y()+100>360){
        setPos(x(),y()-10);
    }
    else if(event->key() == Qt::Key_S and y()+200<720){
        setPos(x(),y()+10);
    }
    else if(event->key() == Qt::Key_A and x()>190){
        setPos(x()-10,y());
    }
    else if(event->key() == Qt::Key_D and x()+100<1090){
        setPos(x()+10,y());
    }
    if(event->key() == Qt::Key_Space){
        Bullet *bullet = new Bullet();
        bullet->setPos(x()+50,y());
        scene()->addItem(bullet);
    }
}
