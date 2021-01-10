#include "level1.h"
#include "ui_level1.h"

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

    timerE = new QTimer();
    connect(timerE,SIGNAL(timeout()),this,SLOT(makeEnemies()));
    timerE->start(3000);

}

Level1::~Level1()
{
    delete ui;
}

void Level1::FocusPlayer()
{
    ui->graphicsView->centerOn(player->x(),player->y()-250);
}

double Level1::playerPos()
{
    return player->y();
}

void Level1::makeEnemies()
{
    enemy = new Enemy();
    scene->addItem(enemy);
}
