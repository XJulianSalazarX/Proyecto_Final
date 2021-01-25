#include "level1.h"
#include "ui_level1.h"
#include "menu.h"
#include <QDebug>

extern Menu *menu;

Level1::Level1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Level1)
{
    ui->setupUi(this);

    posx = 0;
    isBoss = false;
    ui->showScore->setVisible(false);

    ui->cont->setVisible(false);
    ui->retry->setVisible(false);
    ui->home->setVisible(false);

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
    ui->progressBar_2->setVisible(false);
    playerHealth();

    //Poner focus sobre el item (reciba la tacla que se presione por teclado)
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //generar enemigos
    timerE = new QTimer();
    connect(timerE,SIGNAL(timeout()),this,SLOT(makeEnemies()));
    timerE->start(2000);

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

void Level1::playerScore(int increase)
{
    ui->score->display(ui->score->intValue()+increase);
}

void Level1::Final()
{
    isBoss = true;
    timerB->stop();
    timerE->stop();

    scene->clear();

    if(menu->getLevel() == 1){

        scene->setBackgroundBrush(QPixmap(":/images/level 1.2.jpg"));
        ui->graphicsView->setSceneRect(0,0,width(),720);

        player = new Character(true);
        scene->addItem(player);
        player->setPos(630,650);
        playerHealth();

        //Poner focus sobre el item (reciba la tacla que se presione por teclado)
        player->setFlag(QGraphicsItem::ItemIsFocusable);
        player->setFocus();

        boss = new Boss();
        scene->addItem(boss);

        ui->progressBar_2->setVisible(true);
        ui->progressBar_2->setRange(0,100);
        BossHealth();

        //poder
        power = new Power();
        scene->addItem(power);
    }
    else if(menu->getLevel() == 2){

        scene->setBackgroundBrush(QPixmap(":/images/level 2.2.jpg"));
        ui->graphicsView->setSceneRect(0,0,width(),720);

        player = new Character(true);
        scene->addItem(player);
        player->setPos(630,650);
        playerHealth();

        //Poner focus sobre el item (reciba la tacla que se presione por teclado)
        player->setFlag(QGraphicsItem::ItemIsFocusable);
        player->setFocus();

        //poder
        power = new Power();
        scene->addItem(power);
    }
}

void Level1::BossHealth()
{
    if(menu->getLevel() == 1)
        ui->progressBar_2->setValue(boss->getHealth());
}

double Level1::getPlayerHealth()
{
    return ui->progressBar->value();
}

void Level1::returnMenu()
{
    timerB->stop();
    timerE->stop();

    scene->clear();

    scene->setBackgroundBrush(QPixmap(":/images/fondo.jpg").scaled(1280,720));
    ui->graphicsView->setSceneRect(0,0,width(),720);

    ui->showScore->setNum(ui->score->intValue());
    ui->showScore->setVisible(true);

    ui->retry->setVisible(true);
    ui->home->setVisible(true);
    ui->stop->setVisible(false);
}

void Level1::complete()
{
    scene->removeItem(power);
    delete power;
    ui->stop->setVisible(false);
    ui->showScore->setNum(ui->score->intValue());
    ui->showScore->setVisible(true);
    ui->home->setVisible(true);
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
    disconnect(timerE,SIGNAL(timeout()),this,SLOT(makeEnemies()));
    connect(timerE,SIGNAL(timeout()),this,SLOT(makeObstacles()));
    timerE->start(2000);
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

    timerE->stop();
    disconnect(timerE,SIGNAL(timeout()),this,SLOT(makeObstacles()));
    connect(timerE,SIGNAL(timeout()),this,SLOT(makeEnemies2()));
    timerE->start(2000);
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
    timerE->stop();

    disconnect(timerE,SIGNAL(timeout()),this,SLOT(makeEnemies2()));
    connect(timerE,SIGNAL(timeout()),this,SLOT(makeObstacles2()));
    timerE->start(2000);
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

    timerE->stop();
    disconnect(timerE,SIGNAL(timeout()),this,SLOT(makeObstacles2()));
    connect(timerE,SIGNAL(timeout()),this,SLOT(makeEnemies()));
    timerE->start(2000);
}

void Level1::makeBonus()
{
    bonus = new Bonus();
    scene->addItem(bonus);
}

void Level1::on_stop_clicked()
{
    if(!isBoss){
        timerB->stop();
        timerE->start();
        player->stopMove();
    }
//    enemy->stopMove();
//    enemy2->stopMove();
//    obs->stopMove();
//    obs2->stopMove();
//    bonus->stopMove();
    ui->cont->setVisible(true);
    ui->retry->setVisible(true);
    ui->home->setVisible(true);
}

void Level1::on_cont_clicked()
{
    if(!isBoss){
        timerB->start();
        timerE->start();
        player->continueMove();
    }

    ui->cont->setVisible(false);
    ui->retry->setVisible(false);
    ui->home->setVisible(false);
}

void Level1::on_retry_clicked()
{
    scene->clear();
    close();
    menu->show();
    delete this;
    return;
}

void Level1::on_home_clicked()
{
    scene->clear();
    close();
    menu->show();
    menu->on_back_clicked();

    delete this;
    return;
}
