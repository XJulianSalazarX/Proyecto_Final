#include "character.h"
#include "menu.h"
#include <QDebug>

extern Menu *menu;

Character::Character(bool boss,QObject *parent):QObject(parent)
{
    if(boss == true){
        if(menu->getCharacter() == 1)
            pixmap = new QPixmap(":/images/character 1.png");
        else if(menu->getCharacter() == 2)
            pixmap = new QPixmap(":/images/character 2.png");
        else if(menu->getCharacter() == 3)
            pixmap = new QPixmap(":/images/character 3.png");

        col = 0;
        w = 142.75;
        h = 67;
        last = 571;

        min = 70;
        max = 1240;

        health = menu->level1->getPlayerHealth();
        speed = 10;

        timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(actualize()));
        timer->start(100);

        timerS = new QTimer();
        connect(timerS,SIGNAL(timeout()),this,SLOT(Shoot()));
        timerS->start(500);

        timerBoss = new QTimer();
        connect(timerBoss,SIGNAL(timeout()),this,SLOT(End()));
        timerBoss->start(20);
    }

    else{
        if(menu->getCharacter() == 1)
            pixmap = new QPixmap(":/images/character1.2.png");
        else if(menu->getCharacter() == 2)
            pixmap = new QPixmap(":/images/character2.2.png");
        else if(menu->getCharacter() == 3)
            pixmap = new QPixmap(":/images/character3.2.png");

        col=0;
        w = 55;
        h = 92;
        last = 110;

        health = 10;
        speed = 7.5;

        min = 30;
        max = 1090;

        timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(actualize()));
        timer->start(250);

        timerM = new QTimer();
        connect(timerM,SIGNAL(timeout()),this,SLOT(Move()));
        timerM->start(20);

        timerS = new QTimer();
        connect(timerS,SIGNAL(timeout()),this,SLOT(Shoot()));
        timerS->start(500);

        timerMove = new QTimer();
        connect(timerMove,SIGNAL(timeout()),this,SLOT(Slow()));
    }
}

void Character::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A and x()>min){
        setPos(x()-speed,y());
    }
    else if(event->key() == Qt::Key_D and x()+30<max){
        setPos(x()+speed,y());
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

void Character::stopMove()
{
    timerM->stop();
}

void Character::continueMove()
{
    timerM->start();
}

void Character::actualize()
{
    col += w;
    if(col >= last){
        col = 0;
    }
    this->update(-w/2,-h/2,w,h);
}

void Character::Move()
{
    //colisiones
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
                    menu->level1->returnMenu();
                    return;
                }
            }

            else if(typeid (*(i)) == typeid (EnemyBullet)){
                scene()->removeItem(i);
                delete i;
                health --;
                if(health <= 0){
                    scene()->removeItem(this);
                    delete this;
                     menu->level1->returnMenu();
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
                     menu->level1->returnMenu();
                    return;
                }
            }

            else if(typeid (*(i)) == typeid (Obstacle)){
                qDebug() << menu->level1->getObstacle();
                scene()->removeItem(i);
                delete i;
                health -= 2;

                if(health <= 0){
                    scene()->removeItem(this);
                    delete this;
                     menu->level1->returnMenu();
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
                health += 2;
            }
        }
    }
    //actualizar vida
    menu->level1->playerHealth();

    //mover el auto
    setPos(x(),y()-speed);
    menu->level1->FocusPlayer();
    menu->level1->playerHealth();
    if(y() < 0){
        menu->level1->Final();
    }
}

void Character::Shoot()
{
    Bullet *bullet = new Bullet();
    bullet->setPos(x(),y());
    scene()->addItem(bullet);
}

void Character::Slow()
{
    speed = 7.5;
    timerMove->stop();
    timerS->start(500);
}

void Character::End()
{
    //colisiones
    QList<QGraphicsItem *> collisions = collidingItems();
    for(QGraphicsItem *i : collisions){
        if(i->collidesWithItem(this)){
            if(typeid(*(i)) == typeid (EnemyBullet)){
                scene()->removeItem(i);
                delete i;
                health --;
                //menu->level1->playerHealth();
                if(health <= 0){
                    scene()->removeItem(this);
                    delete this;
                    menu->level1->returnMenu();
                    return;
                }
            }
            else if(typeid (*(i)) == typeid (Power)){
                health -= 0.1;
                if (health < 1) health = 0;
                qDebug() << health;
                if(health <= 0){
                    scene()->removeItem(this);
                    delete this;
                     menu->level1->returnMenu();
                    return;
                }
            }
            else if(typeid (*(i)) == typeid (CanonBullet)){
                health -= 2;
                scene()->removeItem(i);
                delete i;
                if(health <= 0){
                    scene()->removeItem(this);
                    delete this;
                     menu->level1->returnMenu();
                    return;
                }
            }
            else if(typeid (*(i)) == typeid (Boss2)){
                health = 0;
                scene()->removeItem(i);
                delete i;
                if(health <= 0){
                    scene()->removeItem(this);
                    delete this;
                    menu->level1->returnMenu();
                    return;
                }
            }
        }
    }
    menu->level1->playerHealth();
}
