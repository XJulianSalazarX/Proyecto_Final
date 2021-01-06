#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);

    this->setMinimumSize(width(),height());
    this->setMaximumSize(width(),height());
    scene = new QGraphicsScene();

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(width(),height()-20);
    ui->graphicsView->setSceneRect(0,0,width(),height()-20);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/images/space.png").scaled(1280,720)));
    ui->splitter->setVisible(false);
    ui->back->setVisible(false);
    ui->levels->setVisible(false);
    ui->characters->setVisible(false);
    ui->play_2->setVisible(false);
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

void Menu::on_play_clicked()
{
    ui->back->setVisible(true);
    ui->levels->setVisible(true);
    ui->characters->setVisible(true);
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
    ui->characters->setVisible(false);
    ui->play_2->setVisible(false);
    ui->back->setVisible(false);
    Visible();
}
