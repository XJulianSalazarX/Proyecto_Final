#include "level1.h"
#include "ui_level1.h"
#include <QDebug>

Level1::Level1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Level1)
{
    ui->setupUi(this);

    posx = 0;

    this->setMinimumSize(width(),height());
    this->setMaximumSize(width(),height());

    //view
    ui->graphicsView->setFixedSize(width(),height()-20);

    //scene
    scene = new QGraphicsScene();
    scene->setBackgroundBrush(QPixmap(":/images/level1.1.jpg"));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setSceneRect(0,0,width(),21600);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //player
    player = new Character();
    scene->addItem(player);
    //player->setPos(630,21500);
    player->setPos(630,720);
    ui->graphicsView->centerOn(player->x(),player->y());
    ui->progressBar->setRange(0,10);
    playerHealth();

    //Poner focus sobre el item (reciba la tacla que se presione por teclado)
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //generar enemigos
    timerE = new QTimer();
    connect(timerE,SIGNAL(timeout()),this,SLOT(makeEnemies()));
    timerE->start(2000);

    //generar obstaculos
    timerO = new QTimer();
    connect(timerO,SIGNAL(timeout()),this,SLOT(makeObstacles()));

    //generar tanques enemigos
    timerE2 = new QTimer();
    connect(timerE2,SIGNAL(timeout()),this,SLOT(makeEnemies2()));

    //generar obstaculos 2
    timerO2 = new QTimer();
    connect(timerO2,SIGNAL(timeout()),this,SLOT(makeObstacles2()));

    //generar bonus
    timerB = new QTimer();
    connect(timerB,SIGNAL(timeout()),this,SLOT(makeBonus()));
    timerB->start(20000);
}

Level1::~Level1()
{
    delete ui;
}

void Level1::FocusPlayer()
{
    ui->graphicsView->centerOn(player->x(),player->y()-300);
}

double Level1::playerPos()
{
    return player->y();
}

int Level1::getObstacle()
{
    return obs->getType_obs();
}

void Level1::playerHealth()
{
    ui->progressBar->setValue(player->getHealth());
}

void Level1::Final()
{
    timerB->stop();
    timerE->stop();
    timerO->stop();
    timerE2->stop();
    timerO2->stop();

    scene->clear();

    scene->setBackgroundBrush(QPixmap(":/images/level 1.2.jpg"));
    ui->graphicsView->setSceneRect(0,0,width(),720);

    player = new Character(true);
    scene->addItem(player);
    player->setPos(630,650);

    //Poner focus sobre el item (reciba la tacla que se presione por teclado)
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
}

void Level1::makeEnemies()
{
    int random;
    do{
        random = 190 +rand() % (800-190);
    }while(abs(posx-random) < 100);
    posx = random;

    enemy = new Enemy(posx);
    scene->addItem(enemy);
    timerE->stop();
    timerO->start(2000);
}

void Level1::makeObstacles()
{
    int random;
    do{
        random = 190 +rand() % (800-190);
    }while(abs(posx-random) < 100);
    posx = random;

    obs = new Obstacle(posx);
    scene->addItem(obs);
    timerO->stop();
    timerE2->start(2000);
}

void Level1::makeEnemies2()
{
    int random;
    do{
        random = 190 +rand() % (800-190);
    }while(abs(posx-random) < 100);
    posx = random;

    enemy2 = new EnemyShoots(posx);
    scene->addItem(enemy2);
    timerE2->stop();
    timerO2->start(2000);
}

void Level1::makeObstacles2()
{
    int random;
    do{
        random = 190 +rand() % (800-190);
    }while(abs(posx-random) < 100);
    posx = random;

    obs2 = new Obstacle2(posx);
    scene->addItem(obs2);
    timerO2->stop();
    timerE->start(2000);
}

void Level1::makeBonus()
{
    bonus = new Bonus();
    scene->addItem(bonus);
}
