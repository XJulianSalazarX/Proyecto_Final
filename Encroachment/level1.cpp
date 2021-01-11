#include "level1.h"
#include "ui_level1.h"
#include <QDebug>

Level1::Level1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Level1)
{
    ui->setupUi(this);

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
    player->setPos(630,21500);
    ui->graphicsView->centerOn(player->x(),player->y());

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

void Level1::makeEnemies()
{
    enemy = new Enemy();
    scene->addItem(enemy);
    timerE->stop();
    timerO->start(2000);
}

void Level1::makeObstacles()
{
    qDebug() << "generar obstaculo";
    obs = new Obstacle();
    scene->addItem(obs);
    timerO->stop();
    timerE2->start(2000);
}

void Level1::makeEnemies2()
{
    enemy2 = new EnemyShoots();
    scene->addItem(enemy2);
    timerE2->stop();
    timerE->start(2000);
}

void Level1::makeBonus()
{
    bonus = new Bonus();
    scene->addItem(bonus);
}
