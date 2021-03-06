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
        if(menu->getMult() == true)
            health = menu->multiplayer->getPlayerHealth();
        else
            health = menu->level1->getPlayerHealth();

        speed = 5;

        timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(actualize()));
        timer->start(100);

        timerM = new QTimer();
        connect(timerM,SIGNAL(timeout()),this,SLOT(End()));
        timerM->start(20);
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

        health = 100;
        speed = 7.5;

        min = 210;
        max = 1090;

        timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(actualize()));
        timer->start(250);

        timerM = new QTimer();
        connect(timerM,SIGNAL(timeout()),this,SLOT(Move()));
        timerM->start(20);

        timerMove = new QTimer();
        connect(timerMove,SIGNAL(timeout()),this,SLOT(Slow()));
    }

    timerS = new QTimer();
    connect(timerS,SIGNAL(timeout()),this,SLOT(Shoot()));
    timerS->start(500);

}

Character::~Character()
{
    delete timer;
    delete timerS;
    delete timerM;

}

void Character::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A and x()>min){
        setPos(x()-speed-5,y());
    }
    else if(event->key() == Qt::Key_D and x()+30<max){
        setPos(x()+speed+5,y());
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
    timerS->stop();
}

void Character::continueMove()
{
    timerM->start();
    timerS->start();
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
                health -= 3;
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
                health -= 5;
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
                health -= 10;

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
                health -= 7;
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
                short num = 5 + rand()%(11-5);
                health += num;
                if(health > 100)
                    health = 100;
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
                health -= 7;
                //menu->level1->playerHealth();
                if(health <= 0){
                    scene()->removeItem(this);
                    delete this;
                    if(!menu->getMult())
                        menu->level1->returnMenu();
                    else{
                        menu->multiplayer->setBoss_win(true);
                        menu->multiplayer->endTurn();
                    }
                    return;
                }
            }
            else if(typeid (*(i)) == typeid (Power)){
                health -= 1;
                qDebug() << health;
                if(health <= 0){
                    scene()->removeItem(this);
                    delete this;
                    if(!menu->getMult())
                        menu->level1->returnMenu();
                    else{
                        menu->multiplayer->setBoss_win(true);
                        menu->multiplayer->endTurn();
                    }
                    return;
                }
            }
            else if(typeid (*(i)) == typeid (CanonBullet)){
                health -= 15;
                scene()->removeItem(i);
                delete i;
                if(health <= 0){
                    scene()->removeItem(this);
                    delete this;
                    if(!menu->getMult())
                        menu->level1->returnMenu();
                    else{
                        menu->multiplayer->setBoss_win(true);
                        menu->multiplayer->endTurn();
                    }
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
                    if(!menu->getMult())
                        menu->level1->returnMenu();
                    else{
                        menu->multiplayer->setBoss_win(true);
                        menu->multiplayer->endTurn();
                    }
                    return;
                }
            }
        }
    }
    if(!menu->getMult())
        menu->level1->playerHealth();
    else
        menu->multiplayer->playerHealth();
}
