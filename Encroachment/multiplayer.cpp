#include "multiplayer.h"
#include "ui_multiplayer.h"
#include "menu.h"

extern Menu *menu;

Multiplayer::Multiplayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Multiplayer)
{
    ui->setupUi(this);
    player1 = menu->getUsername();

    ui->progressBar->setVisible(false);
    ui->progressBar_2->setVisible(false);

    level = 0;
    character = 0;

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
    scene->setBackgroundBrush(QBrush(QImage(":/images/fondo.jpg").scaled(1280,720)));

}

Multiplayer::~Multiplayer()
{
    delete ui;
}

void Multiplayer::selectLevel()
{
    ui->username->setVisible(false);
    ui->password->setVisible(false);
    ui->label->setVisible(false);
    ui->label_2->setVisible(false);
    ui->levels->setVisible(true);
    ui->characteres->setVisible(true);
}

void Multiplayer::startGame()
{
    ui->progressBar->setVisible(true);
    ui->progressBar->setRange(0,100);
    ui->progressBar->setValue(100);
    ui->progressBar_2->setVisible(true);
    ui->progressBar_2->setRange(0,100);
    ui->levels->setVisible(false);
    ui->characteres->setVisible(false);
    ui->back->setVisible(false);
    ui->next->setVisible(false);

    menu->setLevel(level);
    menu->setCharacter(character);

    if(menu->getLevel() == 1){

        scene->setBackgroundBrush(QPixmap(":/images/level 1.2.jpg"));
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
    power = new Power(90,4,0.05);
    scene->addItem(power);
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
            selectLevel();
            return;
        }
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
    close();
    delete this;
    return;
}
