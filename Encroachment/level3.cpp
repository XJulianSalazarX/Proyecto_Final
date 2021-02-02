#include "level3.h"
#include "ui_level3.h"

Level3::Level3(Level1 *parent) :
    Level1(parent),
    ui(new Ui::Level3)
{
    ui->setupUi(this);

    scene->setBackgroundBrush(QPixmap(":/images/level3.1.jpg"));

    disconnect(timerE,SIGNAL(timeout()),this,SLOT(makeEnemies()));
    connect(timerE,SIGNAL(timeout()),this,SLOT(makeEnemies()));
    timerE->start(1750);
}

Level3::~Level3()
{
    delete ui;
}

void Level3::makeEnemies()
{
    int random,pos;
    pos = posx;
    for(short i = 0; i < 3; i++){
        do{
            random = 190 +rand() % (800-190);
        }while(abs(posx-random) < 150 and abs(pos-random) < 150);
        posx = pos;
        pos = random;

        enemy = new Enemy(pos);
        scene->addItem(enemy);
    }
    posx = random;
    timerE->stop();
    disconnect(timerE,SIGNAL(timeout()),this,SLOT(makeEnemies()));
    connect(timerE,SIGNAL(timeout()),this,SLOT(makeObstacles()));
    timerE->start(1500);
}

void Level3::makeObstacles()
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
    timerE->start(1500);
}

void Level3::makeEnemies2()
{
    int random;
    for(short i = 0; i < 3; i++){
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
    timerE->start(1500);
}

void Level3::makeObstacles2()
{
    int random;
    for(short i = 0; i < 2; i++){
        do{
            random = 190 +rand() % (800-190);
        }while(abs(posx-random) < 100);
        posx = random;

        obs2 = new Obstacle2(posx);
        scene->addItem(obs2);
    }

    timerE->stop();
    disconnect(timerE,SIGNAL(timeout()),this,SLOT(makeObstacles2()));
    connect(timerE,SIGNAL(timeout()),this,SLOT(makeEnemies()));
    timerE->start(1500);
}
