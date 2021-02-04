#include "level2.h"
#include "ui_level2.h"
#include "menu.h"

extern Menu *menu;

Level2::Level2(Level1 *parent) :
    Level1(parent),
    ui(new Ui::Level2)
{
    ui->setupUi(this);
        setWindowTitle("Encroachment");
    scene->setBackgroundBrush(QPixmap(":/images/level2.1.jpg"));

    disconnect(timerE,SIGNAL(timeout()),this,SLOT(makeEnemies()));
    connect(timerE,SIGNAL(timeout()),this,SLOT(makeEnemies()));
    timerE->start(1750);
}

Level2::~Level2()
{
    delete ui;
}

void Level2::makeEnemies()
{
    int random;
    for(short i = 0; i < 2; i++){
        do{
            random = 190 +rand() % (800-190);
        }while(abs(posx-random) < 150);
        posx = random;

        enemy = new Enemy(posx);
        scene->addItem(enemy);
    }

    timerE->stop();
    disconnect(timerE,SIGNAL(timeout()),this,SLOT(makeEnemies()));
    connect(timerE,SIGNAL(timeout()),this,SLOT(makeObstacles()));
    timerE->start(1750);
}

void Level2::makeObstacles()
{
    int random;
    for(short i = 0; i < 2; i++){
        do{
            random = 190 +rand() % (800-190);
        }while(abs(posx-random) < 150);
        posx = random;

        obs = new Obstacle(posx);
        scene->addItem(obs);
    }

    timerE->stop();
    disconnect(timerE,SIGNAL(timeout()),this,SLOT(makeObstacles()));
    connect(timerE,SIGNAL(timeout()),this,SLOT(makeEnemies2()));
    timerE->start(1750);
}

void Level2::makeEnemies2()
{
    int random;
    for(short i = 0; i < 2; i++){
        do{
            random = 190 +rand() % (800-190);
        }while(abs(posx-random) < 150);
        posx = random;

        enemy2 = new EnemyShoots(posx);
        scene->addItem(enemy2);
    }
    timerE->stop();

    disconnect(timerE,SIGNAL(timeout()),this,SLOT(makeEnemies2()));
    connect(timerE,SIGNAL(timeout()),this,SLOT(makeObstacles2()));
    timerE->start(1750);
}

void Level2::makeObstacles2()
{
    int random;
    for(short i = 0; i < 2; i++){
        do{
            random = 190 +rand() % (800-190);
        }while(abs(posx-random) < 150);
        posx = random;

        obs2 = new Obstacle2(posx);
        scene->addItem(obs2);
    }

    timerE->stop();
    disconnect(timerE,SIGNAL(timeout()),this,SLOT(makeObstacles2()));
    connect(timerE,SIGNAL(timeout()),this,SLOT(makeEnemies()));
    timerE->start(1750);
}
