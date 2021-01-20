#include "menu.h"
#include "ui_menu.h"
#include <QDebug>

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);

    ui->splitter->setGeometry(482,150,316,420);
    ui->start->setGeometry(482,400,316,140);

    this->setMinimumSize(width(),height());
    this->setMaximumSize(width(),height());
    scene = new QGraphicsScene();

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(width(),height()-20);
    ui->graphicsView->setSceneRect(0,0,width(),height()-20);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/images/fondo.jpg").scaled(1280,720)));
    ui->splitter->setVisible(false);
    ui->back->setVisible(false);
    ui->levels->setVisible(false);
    ui->play_2->setVisible(false);

    ui->play->setVisible(false);
    ui->top->setVisible(false);
    ui->profile->setVisible(false);
    ui->settings->setVisible(false);
    ui->howToPLay->setVisible(false);
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
}

void Menu::Invisible()
{
    ui->play->setVisible(false);
    ui->profile->setVisible(false);
    ui->top->setVisible(false);
    ui->settings->setVisible(false);
    ui->howToPLay->setVisible(false);
}

void Menu::showMenu()
{
    ui->play->setVisible(true);
    ui->top->setVisible(true);
    ui->profile->setVisible(true);
    ui->settings->setVisible(true);
    ui->howToPLay->setVisible(true);
}

void Menu::on_play_clicked()
{
    ui->back->setVisible(true);
    ui->levels->setVisible(true);
    ui->play_2->setVisible(true);
    Invisible();
}

void Menu::on_howToPLay_clicked()
{
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
    ui->splitter->setVisible(false);
    ui->levels->setVisible(false);
    ui->play_2->setVisible(false);
    ui->back->setVisible(false);
    Visible();
    level = 0;
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
}

void Menu::on_level2_clicked()
{
    level = 2;
}

void Menu::on_level3_clicked()
{
    level = 3;
}

void Menu::on_play_2_clicked()
{
    switch (level) {
    case 1:{
       close();
       qDebug() << "Nivel 1";
       level1 = new Level1();
       level1->show();
    }
        break;
    case 2:{
        qDebug() << "Nivel 2";
    }
        break;
    case 3:{
        qDebug() << "Nivel 3";
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
     //showMenu();
}
