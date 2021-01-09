#include "character.h"

Character::Character(QObject *parent):QObject(parent)
{
    //setPixmap(QPixmap(":/images/carrito_bueno.png"));
    pixmap = new QPixmap(":/images/character 1.2.png");

    col=0;
    w = 70;
    h = 140;

    health = 100;

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(actualize()));
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

QRectF Character::boundingRect() const
{
    return QRectF(-w/2,-h/2,w,h);
}

void Character::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    option = nullptr;
    widget = nullptr;
    painter->drawPixmap(-w/2,-w/2,*pixmap,col,0,w,h);
}

void Character::actualize()
{
    col += 70;
    if(col >= 140){
        col = 0;
    }
    this->update(-w/2,-h/2,w,h);
}
