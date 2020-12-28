#include "widget.h"
#include "ui_widget.h"

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
    scene->setBackgroundBrush(QPixmap(":/images/Mesa_de_trabajo_1.jpg"));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(width(),height()-20);
    ui->graphicsView->setSceneRect(0,0,width(),height()-20);
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
    T_enemies = new QTimer();
    connect(T_enemies,SIGNAL(timeout()),this,SLOT(Enemies()));
    T_enemies->start(3000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::Enemies()
{
    Enemy *enemy = new Enemy();
    scene->addItem(enemy);
}

