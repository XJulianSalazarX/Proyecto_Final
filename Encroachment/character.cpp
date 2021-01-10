#include "character.h"
#include "menu.h"

extern Menu *menu;

Character::Character(QObject *parent):QObject(parent)
{
    //setPixmap(QPixmap(":/images/carrito_bueno.png"));
    pixmap = new QPixmap(":/images/character 1.2.png");

    col=0;
    w = 60;
    h = 140;

    health = 100;

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(actualize()));
    //timer->start(1000);

    timerM = new QTimer();
    connect(timerM,SIGNAL(timeout()),this,SLOT(Move()));
    timerM->start(18);
}

void Character::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A and x()>220){
        setPos(x()-10,y());
    }
    else if(event->key() == Qt::Key_D and x()+30<1090){
        setPos(x()+10,y());
    }
    if(event->key() == Qt::Key_Space){
        Bullet *bullet = new Bullet();
        bullet->setPos(x(),y());
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
    painter->drawPixmap(-w/2,-h/2,*pixmap,col,0,w,h);
}

void Character::actualize()
{
    col += 60;
    if(col >= 140){
        col = 0;
    }
    this->update(-w/2,-h/2,w,h);
}

void Character::Move()
{
    setPos(x(),y()-5);
    if(menu->getLevel() == 1)
        menu->level1->FocusPlayer();
}
