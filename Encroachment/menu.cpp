#include "menu.h"
#include "ui_menu.h"
#include <QDebug>

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    setWindowTitle("Encroachment");

    level = 0;
    character = 0;
    song = 0;

    ui->label->setVisible(false);

    ui->splitter->setGeometry(482,150,316,420);
    ui->start->setGeometry(520,520,316,140);

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
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/images/objetivo.png").scaled(1280,720)));
    ui->splitter->setVisible(false);
    ui->back->setVisible(false);
    ui->levels->setVisible(false);
    ui->play_2->setVisible(false);

    Invisible();

    sound = new QMediaPlayer();
    timerSound = new QTimer();
    connect(timerSound,SIGNAL(timeout()),this,SLOT(Music()));
    timerSound->start(2000);

}

Menu::~Menu()
{
    delete ui;
}

void Menu::Visible()
{
    ui->play->setVisible(true);
    ui->profile->setVisible(true);
    ui->top->setVisible(true);
    ui->settings->setVisible(true);
    ui->howToPLay->setVisible(true);
    ui->multiplayer->setVisible(true);
}

void Menu::Invisible()
{
    ui->play->setVisible(false);
    ui->profile->setVisible(false);
    ui->top->setVisible(false);
    ui->settings->setVisible(false);
    ui->howToPLay->setVisible(false);
    ui->multiplayer->setVisible(false);
}

void Menu::showMenu()
{
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/images/wallpaper.png").scaled(1280,720)));
    Visible();
}

void Menu::on_play_clicked()
{
    mult = false;
    ui->back->setVisible(true);
    ui->levels->setVisible(true);
    ui->play_2->setVisible(true);
    ui->characteres->setVisible(true);
    Invisible();
}

void Menu::on_howToPLay_clicked()
{
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/images/instrucciones.jpg").scaled(1280,720)));
    ui->back->setVisible(true);
    Invisible();
}

void Menu::on_settings_clicked()
{
    ui->splitter->setVisible(true);
    ui->back->setVisible(true);
    Invisible();
}

void Menu::on_back_clicked()
{
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/images/wallpaper.png").scaled(1280,720)));
    ui->splitter->setVisible(false);
    ui->levels->setVisible(false);
    ui->characteres->setVisible(false);
    ui->play_2->setVisible(false);
    ui->back->setVisible(false);
    Visible();
    level = 0;
    character = 0;
    mult = false;
    ui->level1->setIcon(QIcon(":/images/level1 b.jpg"));
    ui->level1->setIconSize(QSize(350,400));
    ui->level2->setIcon(QIcon(":/images/level2 b.jpg"));
    ui->level2->setIconSize(QSize(350,400));
    ui->level3->setIcon(QIcon(":/images/level3 b.jpg"));
    ui->level3->setIconSize(QSize(350,400));
    ui->character1->setStyleSheet("background-image: url(:/images/character 1.png);");
    ui->character2->setStyleSheet("background-image: url(:/images/character 2.png);");
    ui->character3->setStyleSheet("background-image: url(:/images/character 3.png);");
    ui->label->setVisible(false);
}

void Menu::Music()
{
    short num=0;
    while(song == num){
        num=rand()%3;
    }
    song = num;
    if(num == 0){
        sound->setMedia(QUrl("qrc:/music/choose-mario-kart.mp3"));
        sound->setVolume(30);
        sound->play();
        timerSound->start(30000);
    }
    else if(num == 1){
        sound->setMedia(QUrl("qrc:/music/ringtones-kill-bill-whistle.mp3"));
        sound->setVolume(30);
        sound->play();
        timerSound->start(20000);
    }
    else{
        sound->setMedia(QUrl("qrc:/music/gta-san-andreas-f.mp3"));
        sound->setVolume(30);
        sound->play();
        timerSound->start(30000);
    }
    qDebug() << song;
}

void Menu::setCharacter(short value)
{
    character = value;
}

void Menu::startTimer()
{
    timerSound->start(1000);
}

bool Menu::getMult() const
{
    return mult;
}

void Menu::setLevel(short value)
{
    level = value;
}

short Menu::getCharacter() const
{
    return character;
}

QString Menu::getUsername() const
{
    return username;
}

void Menu::setUsername(const QString &value)
{
    username = value;
}
void Menu::on_level1_clicked()
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

void Menu::on_level2_clicked()
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

void Menu::on_level3_clicked()
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

void Menu::on_play_2_clicked()
{
    if(character == 0){
        QMessageBox::critical(this,"Error","Seleccione un personaje.");
        return;
    }
    if(!CheckLevel(username,level)){
        QMessageBox::critical(this,"Error","Nivel bloqueado.");
        return;
    }

    switch (level) {
    case 1:{
        close();
        timerSound->stop();
        sound->stop();
        qDebug() << "Nivel 1";
        level1 = new Level1();
        level1->show();
    }
        break;
    case 2:{
        close();
        timerSound->stop();
        sound->stop();
        qDebug() << "Nivel 2";
        level1 = new Level2();
        level1->show();
    }
        break;
    case 3:{
        close();
        timerSound->stop();
        sound->stop();
        qDebug() << "Nivel 3";
        level1 = new Level3();
        level1->show();
    }
        break;
    default:{
        QMessageBox::critical(this,"Error","Seleccione un nivel primero.");
        return;
    }
    }
}

void Menu::on_logOut_clicked()
{
    close();
}

short Menu::getLevel() const
{
    return level;
}

void Menu::on_start_clicked()
{
     ui->start->setVisible(false);
     close();
     login = new Login();
     login->show();
}

void Menu::on_character1_clicked()
{
    character = 1;
    ui->character1->setStyleSheet("background-image: url(:/images/character 1.png);"
    "background-color: qradialgradient(spread:repeat, cx:0.5, cy:0.5, radius:0.077, fx:0.5, fy:0.5, stop:0 rgba(0, 169, 255, 147), stop:0.497326 rgba(0, 0, 0, 147), stop:1 rgba(0, 169, 255, 147))");
    ui->character2->setStyleSheet("background-image: url(:/images/character 2.png);");
    ui->character3->setStyleSheet("background-image: url(:/images/character 3.png);");
}

void Menu::on_character2_clicked()
{
   character = 2;
   ui->character2->setStyleSheet("background-image: url(:/images/character 2.png);"
   "background-color: qradialgradient(spread:repeat, cx:0.5, cy:0.5, radius:0.077, fx:0.5, fy:0.5, stop:0 rgba(0, 169, 255, 147), stop:0.497326 rgba(0, 0, 0, 147), stop:1 rgba(0, 169, 255, 147))");
   ui->character1->setStyleSheet("background-image: url(:/images/character 1.png);");
   ui->character3->setStyleSheet("background-image: url(:/images/character 3.png);");
}

void Menu::on_character3_clicked()
{
   character = 3;
   ui->character3->setStyleSheet("background-image: url(:/images/character 3.png);"
   "background-color: qradialgradient(spread:repeat, cx:0.5, cy:0.5, radius:0.077, fx:0.5, fy:0.5, stop:0 rgba(0, 169, 255, 147), stop:0.497326 rgba(0, 0, 0, 147), stop:1 rgba(0, 169, 255, 147))");
   ui->character1->setStyleSheet("background-image: url(:/images/character 1.png);");
   ui->character2->setStyleSheet("background-image: url(:/images/character 2.png);");
}

void Menu::on_deleteProfile_clicked()
{
    deleteUSer(username);
    close();
}

void Menu::on_deleteProgress_clicked()
{
    deleteScore(username);
    on_back_clicked();
}
void Menu::on_multiplayer_clicked()
{
    timerSound->stop();
    sound->stop();
    close();
    mult = true;
    multiplayer = new Multiplayer();
    multiplayer->show();
}

void Menu::on_top_clicked()
{
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/images/fondo.jpg").scaled(1280,720)));
    Invisible();
    ui->back->setVisible(true);
    vector<string> users = usersName();
    ui->label->setVisible(true);
    ui->label->setStyleSheet("font: 15pt Papyrus");
    ui->label->setText("Usuarios:");
    ui->label->setGeometry(500,0,500,720);
    for(auto i=users.begin();i!=users.end();i++){
        ui->label->setText(ui->label->text()+"\n"+QString::fromStdString(*i));
    }

}

void Menu::on_profile_clicked()
{
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/images/fondo.jpg").scaled(1280,720)));
    Invisible();
    ui->back->setVisible(true);
    vector<string> point = playerScore(username);
    ui->label->setVisible(true);
    ui->label->setText(username);
    ui->label->setText(ui->label->text()+"\n"+"Level1: \t\t"+"Level2: \t\t"+"Level3: \t\t");
    ui->label->setGeometry(100,0,1100,720);
    ui->label->setStyleSheet("font: 30pt Papyrus");
    for(short i=0;i<3;i++){
        ui->label->setText(ui->label->text()+"\n"+QString::fromStdString(point[i]));
        ui->label->setText(ui->label->text()+" \t\t"+QString::fromStdString(point[i+3]));
        ui->label->setText(ui->label->text()+" \t\t"+QString::fromStdString(point[i+6]));
    }
}
