#include "widget.h"
#include "login.h"
#include "ui_widget.h"
#include <QImage>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)




{
    ui->setupUi(this);


    //escena
    this->setFixedSize(1280,740);
    this->setMinimumSize(width(),height());
    this->setMaximumSize(width(),height());
    scene = new QGraphicsScene();
    //scene->setBackgroundBrush(QPixmap(QImage(":/images/Mesa_de_trabajo_1.jpg")));
    scene->setBackgroundBrush(QBrush(QImage(":/images/level.png")));
    ui->graphicsView->setScene(scene);
//    ui->graphicsView->setFixedSize(width(),height()-20);
//    ui->graphicsView->setSceneRect(0,0,width(),height()-20);
    ui->graphicsView->setFixedSize(width()*2,height()-20);
    ui->graphicsView->setSceneRect(0,0,width()*2,height()-20);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //jugador
    player = new Character();
    scene->addItem(player);
    player->setPos(width()/2-50,height()-200);

    //Poner focus sobre el item (reciba la tacla que se presione por teclado)
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //generar enemigos
    t_enemies = new QTimer();
    connect(t_enemies,SIGNAL(timeout()),this,SLOT(Enemies()));
    connect(t_enemies,SIGNAL(timeout()),this,SLOT(Enemies2()));
    t_enemies->start(3000);

    //generar obstaculos
    t_obstacles = new QTimer();
    connect(t_obstacles,SIGNAL(timeout()),this,SLOT(respawn()));
    t_obstacles->start(5000);

    //generar bonus
    t_bonus = new QTimer();
    connect(t_bonus,SIGNAL(timeout()),this,SLOT(CreateBonus()));
    t_bonus->start(10000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::Enemies()
{
    enemy = new Enemy();
    scene->addItem(enemy);
}

void Widget::respawn()
{
    obs = new Obstacle();
    scene->addItem(obs);
}

void Widget::CreateBonus()
{
    bonus = new Bonus();
    scene->addItem(bonus);
}

void Widget::Enemies2()
{
    enemy2 = new EnemyShoots();
    scene->addItem(enemy2);
}

