#include "character.h"
#include "menu.h"
#include <QDebug>

extern Menu *menu;

Character::Character(QObject *parent):QObject(parent)
{
    //setPixmap(QPixmap(":/images/carrito_bueno.png"));
    pixmap = new QPixmap(":/images/character 1.2.png");

    col=0;
    w = 55;
    h = 140;

    health = 10;
    speed = 5;

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(actualize()));
    //timer->start(1000);

    timerM = new QTimer();
    connect(timerM,SIGNAL(timeout()),this,SLOT(Move()));
    timerM->start(20);

    timerS = new QTimer();
    connect(timerS,SIGNAL(timeout()),this,SLOT(Shoot()));
    timerS->start(500);

    timerMove = new QTimer();
    connect(timerMove,SIGNAL(timeout()),this,SLOT(Slow()));
}

void Character::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A and x()>220){
        setPos(x()-speed*2,y());
    }
    else if(event->key() == Qt::Key_D and x()+30<1090){
        setPos(x()+speed*2,y());
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

double Character::getHealth() const
{
    return health;
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
    QList<QGraphicsItem *> collisions = collidingItems();
    for(QGraphicsItem *i : collisions){
        if(i->collidesWithItem(this)){
            if(typeid(*(i)) == typeid (Enemy)){
                scene()->removeItem(i);
                delete i;
                health --;
                if(health <= 0){
                    scene()->removeItem(this);
                    delete this;
                    return;
                }
            }

            else if(typeid (*(i)) == typeid (EnemyBullet)){
                scene()->removeItem(i);
                delete i;
                health -= 2;
                if(health <= 0){
                    scene()->removeItem(this);
                    delete this;
                    return;
                }
            }

            else if(typeid (*(i)) == typeid (EnemyShoots)){
                scene()->removeItem(i);
                delete i;
                health -= 3;
                if(health <= 0){
                    scene()->removeItem(this);
                    delete this;
                    return;
                }
            }

            else if(typeid (*(i)) == typeid (Obstacle)){
                qDebug() << menu->level1->getObstacle();
                scene()->removeItem(i);
                delete i;
                health -= 1;

                if(health <= 0){
                    scene()->removeItem(this);
                    delete this;
                    return;
                }
            }

            else if(typeid (*(i)) == typeid (Obstacle2)){
                speed = 2;
                timerMove->start(30);
                timerS->stop();
            }

            else if(typeid (*(i)) == typeid (Bonus)){
                scene()->removeItem(i);
                delete i;
            }
        }
    }

    menu->level1->playerHealth();

    setPos(x(),y()-speed);
    if(menu->getLevel() == 1)
        menu->level1->FocusPlayer();
}

void Character::Shoot()
{
    Bullet *bullet = new Bullet();
    bullet->setPos(x(),y());
    scene()->addItem(bullet);
}

void Character::Slow()
{
    speed = 5;
    timerMove->stop();
    timerS->start(500);
}
