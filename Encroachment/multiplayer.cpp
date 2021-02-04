#include "multiplayer.h"
#include "ui_multiplayer.h"
#include "menu.h"
#include <QDebug>

extern Menu *menu;

Multiplayer::Multiplayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Multiplayer)
{
    ui->setupUi(this);
    setWindowTitle("Multiplayer");
    player1 = menu->getUsername();

    turn2 = false;
    boss_win = false;

    ui->progressBar->setVisible(false);
    ui->progressBar_2->setVisible(false);
    ui->result->setVisible(false);

    ui->playerName->setVisible(false);

    level = 0;
    character = 0;
    time1 = 0;
    time2 = 0;

    ui->levels->setVisible(false);
    ui->levels->setGeometry(245,170,790,190);

    ui->characteres->setGeometry(400,400,450,70);
    ui->characteres->setVisible(false);

    ui->level1->setIcon(QIcon(":/images/level1 b.jpg"));
    ui->level1->setIconSize(QSize(350,400));

    ui->level2->setIcon(QIcon(":/images/level2 b.jpg"));
    ui->level2->setIconSize(QSize(350,400));

    ui->level3->setIcon(QIcon(":/images/level3 b.jpg"));
    ui->level3->setIconSize(QSize(350,400));

    ui->character1->setStyleSheet("background-image: url(:/images/character 1.png);");
    ui->character2->setStyleSheet("background-image: url(:/images/character 2.png);");
    ui->character3->setStyleSheet("background-image: url(:/images/character 3.png);");

    this->setMinimumSize(width(),height());
    this->setMaximumSize(width(),height());
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(width(),height()-20);
    ui->graphicsView->setSceneRect(0,0,width(),height()-20);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/images/fondo.jpg").scaled(1280,720)));
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(time()));

    sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/music/ringtones-game-of-thrones-west.mp3"));
    sound->play();
    sound->setVolume(30);
    changeSound = true;
    timerSound = new QTimer();
    connect(timerSound,SIGNAL(timeout()),this,SLOT(otherMusic()));
    timerSound->start(30000);
}

Multiplayer::~Multiplayer()
{
    delete ui;
    delete sound;
}

void Multiplayer::selectLevel()
{
    if(turn2)
        ui->playerName->setText(player2);
    else
        ui->playerName->setText(player1);

    ui->playerName->setVisible(true);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/images/fondo.jpg").scaled(1280,720)));
    ui->username->setVisible(false);
    ui->password->setVisible(false);
    ui->label->setVisible(false);
    ui->label_2->setVisible(false);
    if(!turn2)
    ui->levels->setVisible(true);
    ui->characteres->setVisible(true);
    ui->next->setVisible(true);
    ui->back->setVisible(true);
}

void Multiplayer::startGame()
{
    if(!CheckLevel(player1,level)){
        QMessageBox::critical(this,"Error","Nivel bloqueado.");
        return;
    }
    ui->progressBar->setVisible(true);
    ui->progressBar->setRange(0,100);
    ui->progressBar->setValue(100);
    ui->progressBar_2->setVisible(true);
    ui->progressBar_2->setRange(0,100);
    ui->levels->setVisible(false);
    ui->characteres->setVisible(false);
    ui->back->setVisible(false);
    ui->next->setVisible(false);

    timer->start(100);

    menu->setLevel(level);
    menu->setCharacter(character);

    if(menu->getLevel() == 1){

        ui->graphicsView->setBackgroundBrush(QPixmap(":/images/level 1.2.jpg"));
        ui->graphicsView->setSceneRect(0,0,width(),720);

        player = new Character(true);
        scene->addItem(player);
        player->setPos(630,650);
        playerHealth();

//        Poner focus sobre el item (reciba la tacla que se presione por teclado)
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

        ui->graphicsView->setBackgroundBrush(QPixmap(":/images/level 2.2.jpg"));
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

        ui->graphicsView->setBackgroundBrush(QPixmap(":/images/level 3.2.jpg"));
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

double Multiplayer::getPlayerHealth()
{
    return ui->progressBar->value();
}

void Multiplayer::playerHealth()
{
    ui->progressBar->setValue(player->getHealth());
}

double Multiplayer::playerPos()
{
    return player->y();
}

double Multiplayer::playerPosX()
{
    return player->x();
}

void Multiplayer::BossHealth()
{
    if(menu->getLevel() == 1)
        ui->progressBar_2->setValue(boss->getHealth());
    if(menu->getLevel() == 2 or menu->getLevel() == 3)
        ui->progressBar_2->setValue(boss2->getHealth());
}

void Multiplayer::changePower()
{
    scene->removeItem(power);
    delete power;
    power = new Power(90,5,0.03);
    scene->addItem(power);
}

void Multiplayer::endTurn()
{
    timer->stop();
    ui->progressBar->setVisible(false);
    ui->progressBar_2->setVisible(false);
    scene->removeItem(power);
    delete power;
    scene->clear();
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/images/fondo.jpg").scaled(1280,720)));
    if(!turn2){
        if(boss_win)
            time1 = 0;
        if(time1 == 0)
            score1 = "No pass";
        else
            score1 = QString::number(time1);
        turn2 = true;
        boss_win = false;
        QMessageBox::information(this,"Information","turno del jugador 2.");
        selectLevel();
    }

    else{
        if(boss_win)
            time2 = 0;
        if(time2 == 0)
            score2 = "No pass";
        else
            score2 = QString::number(time2);
        turn2 = false;
        boss_win = false;
        showResult();
    }
}

void Multiplayer::showResult()
{
    qDebug() << time1 << time2;
    ui->result->setVisible(true);
    if(time1 == time2)
        ui->result->setText(player1+" time : "+score1+"\n"+player2+" time: "+score2+"\n"+"\tDRAW");
    else if(time1 < time2 and time1!=0)
        ui->result->setText(player1+" time : "+score1+"\n"+player2+" time: "+score2+"\n"+"WINNER: "+player1);
    else
        ui->result->setText(player1+" time : "+score1+"\n"+player2+" time: "+score2+"\n"+"WINNER: "+player2);
    ui->back->setVisible(true);
    ui->next->setVisible(true);
}

void Multiplayer::on_next_clicked()
{
    if(ui->username->isVisible()){
        if(ui->username->text() == "" or ui->password->text() == ""){
            QMessageBox::critical(this,"Error","Ingrese nombre de usuario y clave para continuar.");
            return;
        }
        else if(ui->username->text() == player1){
            QMessageBox::critical(this,"Error","No puede ser el mismo usuario.");
            ui->username->setText("");
            ui->password->setText("");
            return;
        }
        else if (existUser(ui->username->text())==false) {
            QMessageBox::critical(this,"Error","El usuario no existe");
            ui->username->setText("");
            ui->password->setText("");
            return;
        }
        else if (CheckPassword(ui->username->text(),ui->password->text())==false){
            QMessageBox::critical(this,"Error","clave incorrecta");
            ui->username->setText("");
            ui->password->setText("");
            return;
        }
        else if(CheckPassword(ui->username->text(),ui->password->text())==true) {
            //pasar a otra pantalla, porque ya inicio sesion
            player2 = ui->username->text();
            QMessageBox::information(this,"Information","turno del jugador 1.");
            selectLevel();
            return;
        }
    }
    else if(ui->result->isVisible()){
        character = 0;
        level = 0;
        time1 = 0;
        time2 = 0;
        ui->levels->setVisible(true);
        ui->characteres->setVisible(true);
        ui->level1->setIcon(QIcon(":/images/level1 b.jpg"));
        ui->level1->setIconSize(QSize(350,400));

        ui->level2->setIcon(QIcon(":/images/level2 b.jpg"));
        ui->level2->setIconSize(QSize(350,400));

        ui->level3->setIcon(QIcon(":/images/level3 b.jpg"));
        ui->level3->setIconSize(QSize(350,400));

        ui->character1->setStyleSheet("background-image: url(:/images/character 1.png);");
        ui->character2->setStyleSheet("background-image: url(:/images/character 2.png);");
        ui->character3->setStyleSheet("background-image: url(:/images/character 3.png);");
        ui->result->setVisible(false);
        turn2 = false;
        selectLevel();

    }
    else{
        if(character == 0){
            QMessageBox::critical(this,"Error","Seleccione un personaje.");
            return;
        }
        else if(level == 0){
            QMessageBox::critical(this,"Error","Seleccione un nivel primero.");
            return;
        }
        startGame();
    }
}

void Multiplayer::on_level1_clicked()
{
    level = 1;
    ui->level1->setMaximumSize(ui->level1->width(),ui->level1->height());
    ui->level1->setIcon(QIcon(":/images/level 1.2.jpg"));
    ui->level1->setIconSize(QSize(350,400));

    ui->level2->setIcon(QIcon(":/images/level2 b.jpg"));
    ui->level2->setIconSize(QSize(350,400));

    ui->level3->setIcon(QIcon(":/images/level3 b.jpg"));
    ui->level3->setIconSize(QSize(350,400));
}

void Multiplayer::on_level2_clicked()
{
    level = 2;
    ui->level2->setMaximumSize(ui->level2->width(),ui->level2->height());
    ui->level2->setIcon(QIcon(":/images/level 2.2.jpg"));
    ui->level2->setIconSize(QSize(350,400));

    ui->level1->setIcon(QIcon(":/images/level1 b.jpg"));
    ui->level1->setIconSize(QSize(350,400));

    ui->level3->setIcon(QIcon(":/images/level3 b.jpg"));
    ui->level3->setIconSize(QSize(350,400));
}

void Multiplayer::on_level3_clicked()
{
    level = 3;
    ui->level3->setMaximumSize(ui->level3->width(),ui->level3->height());
    ui->level3->setIcon(QIcon(":/images/level 3.2.jpg"));
    ui->level3->setIconSize(QSize(350,400));

    ui->level1->setIcon(QIcon(":/images/level1 b.jpg"));
    ui->level1->setIconSize(QSize(350,400));

    ui->level2->setIcon(QIcon(":/images/level2 b.jpg"));
    ui->level2->setIconSize(QSize(350,400));
}

void Multiplayer::on_character1_clicked()
{
    character = 1;
    ui->character1->setStyleSheet("background-image: url(:/images/character 1.png);"
    "background-color: qradialgradient(spread:repeat, cx:0.5, cy:0.5, radius:0.077, fx:0.5, fy:0.5, stop:0 rgba(0, 169, 255, 147), stop:0.497326 rgba(0, 0, 0, 147), stop:1 rgba(0, 169, 255, 147))");
    ui->character2->setStyleSheet("background-image: url(:/images/character 2.png);");
    ui->character3->setStyleSheet("background-image: url(:/images/character 3.png);");

}

void Multiplayer::on_character2_clicked()
{
    character = 2;
    ui->character2->setStyleSheet("background-image: url(:/images/character 2.png);"
    "background-color: qradialgradient(spread:repeat, cx:0.5, cy:0.5, radius:0.077, fx:0.5, fy:0.5, stop:0 rgba(0, 169, 255, 147), stop:0.497326 rgba(0, 0, 0, 147), stop:1 rgba(0, 169, 255, 147))");
    ui->character1->setStyleSheet("background-image: url(:/images/character 1.png);");
    ui->character3->setStyleSheet("background-image: url(:/images/character 3.png);");
}

void Multiplayer::on_character3_clicked()
{
    character = 3;
    ui->character3->setStyleSheet("background-image: url(:/images/character 3.png);"
    "background-color: qradialgradient(spread:repeat, cx:0.5, cy:0.5, radius:0.077, fx:0.5, fy:0.5, stop:0 rgba(0, 169, 255, 147), stop:0.497326 rgba(0, 0, 0, 147), stop:1 rgba(0, 169, 255, 147))");
    ui->character1->setStyleSheet("background-image: url(:/images/character 1.png);");
    ui->character2->setStyleSheet("background-image: url(:/images/character 2.png);");
}

void Multiplayer::on_back_clicked()
{
    menu->show();
    menu->setLevel(0);
    menu->setCharacter(0);
    close();
    delete this;
    menu->startTimer();
    return;
}

void Multiplayer::setBoss_win(bool value)
{
    boss_win = value;
}

void Multiplayer::time()
{
    if(!turn2)
        time1 += 0.1;
    else time2 += 0.1;
}

void Multiplayer::otherMusic()
{
    if(changeSound == true){
        changeSound = false;
        sound->setMedia(QUrl("qrc:/music/rocky.mp3"));
        sound->setVolume(30);
        sound->play();
        timer->start(37000);
    }
    else{
        changeSound = true;
        sound->setMedia(QUrl("qrc:/music/ringtones-game-of-thrones-west.mp3"));
        sound->setVolume(30);
        sound->play();
        timer->start(30000);
    }
}
