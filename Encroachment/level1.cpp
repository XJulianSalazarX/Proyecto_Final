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
    setWindowTitle("Encroachment");

    posx = 0;
    song = 0;
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
    ui->graphicsView->setSceneRect(0,0,width(),10800);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //player
    player = new Character();
    scene->addItem(player);
    player->setPos(630,10700);
    //player->setPos(630,720);
    ui->graphicsView->centerOn(player->x(),player->y());
    ui->progressBar->setRange(0,100);
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

    sound = new QMediaPlayer();

    timerSound = new QTimer();
    connect(timerSound,SIGNAL(timeout()),this,SLOT(Music()));
    timerSound->start(2000);
}

Level1::~Level1()
{
    delete ui;
    delete sound;
    delete timerSound;
}

void Level1::FocusPlayer()
{
    ui->graphicsView->centerOn(player->x(),player->y()-300);
}

double Level1::playerPos()
{
    return player->y();
}

double Level1::playerPosX()
{
    return player->x();
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
    timerSound->stop();
    timerSound->start(1000);
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

        boss2 = new Boss2();
        scene->addItem(boss2);

        ui->progressBar_2->setVisible(true);
        ui->progressBar_2->setRange(0,100);
        BossHealth();

        //poder
        power = new Power();
        scene->addItem(power);
    }
    else if(menu->getLevel() == 3){

        scene->setBackgroundBrush(QPixmap(":/images/level 3.2.jpg"));
        ui->graphicsView->setSceneRect(0,0,width(),720);

        player = new Character(true);
        scene->addItem(player);
        player->setPos(630,650);
        playerHealth();

        //Poner focus sobre el item (reciba la tacla que se presione por teclado)
        player->setFlag(QGraphicsItem::ItemIsFocusable);
        player->setFocus();

        boss2 = new Boss2(true);
        scene->addItem(boss2);

        ui->progressBar_2->setVisible(true);
        ui->progressBar_2->setRange(0,100);
        BossHealth();

        //poder
        power = new Power();
        scene->addItem(power);
    }
}

void Level1::BossHealth()
{
    if(menu->getLevel() == 1)
        ui->progressBar_2->setValue(boss->getHealth());
    if(menu->getLevel() == 2 or menu->getLevel() == 3)
        ui->progressBar_2->setValue(boss2->getHealth());
}

double Level1::getPlayerHealth()
{
    return ui->progressBar->value();
}

void Level1::returnMenu()
{
    timerSound->stop();
    sound->stop();
    sound->setMedia(QUrl("qrc:/music/resident-evil-game-over.mp3"));
    sound->setVolume(15);
    sound->play();

    playerHealth();
    timerB->stop();
    timerE->stop();

    GoScore(menu->getUsername(),QString::number(ui->score->intValue()),menu->getLevel());

    scene->clear();

    scene->setBackgroundBrush(QPixmap(":/images/fondo.jpg").scaled(1280,720));
    ui->graphicsView->setSceneRect(0,0,width(),720);

    ui->showScore->setText("score: "+QString::number(ui->score->intValue())+"\nYOU LOST");
    ui->showScore->setVisible(true);

    ui->retry->setVisible(true);
    ui->home->setVisible(true);
    ui->stop->setVisible(false);
}

void Level1::complete()
{
    timerSound->stop();
    sound->stop();
    sound->setMedia(QUrl("qrc:/music/victory.mp3"));
    sound->setVolume(15);
    sound->play();

    scene->clear();
    GoScore(menu->getUsername(),QString::number(ui->score->intValue()),menu->getLevel());
    if(menu->getLevel()==1 and !CheckLevel(menu->getUsername(),2) and !CheckLevel(menu->getUsername(),3))
        UpdateLevel(menu->getUsername(),menu->getLevel());
    else if(menu->getLevel()==2 and !CheckLevel(menu->getUsername(),3))
        UpdateLevel(menu->getUsername(),menu->getLevel());
    else if(menu->getLevel()==3)
        UpdateLevel(menu->getUsername(),menu->getLevel());
    ui->stop->setVisible(false);
    ui->showScore->setText("score: "+QString::number(ui->score->intValue())+"\nYOU WON");
    ui->showScore->setVisible(true);
    ui->home->setVisible(true);
}

void Level1::changePower()
{
    scene->removeItem(power);
    delete power;
    power = new Power(90,5,0.03);
    scene->addItem(power);
}

void Level1::makeEnemies()
{
    int random;
    do{
        random = 190 +rand() % (800-190);
    }while(abs(posx-random) < 150);
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
    }while(abs(posx-random) < 150);
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
    }while(abs(posx-random) < 150);
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
    }while(abs(posx-random) < 150);
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

void Level1::Music()
{
    short num = 0;
    while(num == song){
        num=rand()%3;
    }
    song = num;
    if(isBoss){
        if(num == 0){
            sound->setMedia(QUrl("qrc:/music/assasin-3-assasin.mp3"));
            sound->setVolume(10);
            sound->play();
        }
        else if(num == 1){
            sound->setMedia(QUrl("qrc:/music/musica-peliculas-15-.mp3"));
            sound->setVolume(10);
            sound->play();
        }
        else{
            sound->setMedia(QUrl("qrc:/music/ringtones-of-caribbean.mp3"));
            sound->setVolume(10);
            sound->play();
        }
        timerSound->start(30000);
    }
    else{
        if(num == 0){
            sound->setMedia(QUrl("qrc:/music/kill-bill-sirena.mp3"));
            sound->setVolume(10);
            sound->play();
            timerSound->start(15000);
        }
        else if(num == 1){
            sound->setMedia(QUrl("qrc:/music/mision-imposible-peliculas-.mp3"));
            sound->setVolume(10);
            sound->play();
            timerSound->start(32000);
        }
        else{
            sound->setMedia(QUrl("qrc:/music/pulp-fiction-tiempos-violentos-peliculas-.mp3"));
            sound->setVolume(10);
            sound->play();
            timerSound->start(25000);
        }
    }
}

void Level1::on_stop_clicked()
{
    if(!isBoss){
        timerB->stop();
        timerE->stop();
        player->stopMove();
    }
    else if(menu->getLevel() == 1){
        boss->stopMove();
        player->stopMove();
    }
    else{
        boss2->stopMove();
        player->stopMove();
    }

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
    else if(menu->getLevel() == 1){
        boss->continueMove();
        player->continueMove();
    }
    else{
        boss2->continueMove();
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
    menu->startTimer();
    return;
}

void Level1::on_home_clicked()
{
    scene->clear();
    close();
    menu->show();
    menu->startTimer();
    menu->on_back_clicked();
    delete this;
    menu->startTimer();
    return;
}
