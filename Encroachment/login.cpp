#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);


    this->setMinimumSize(width(),height());
    this->setMaximumSize(width(),height());
    scene_login = new QGraphicsScene();


}

login::~login()
{
    delete ui;
}


void login::Invisible_login()
{
    //label
     ui->label->setVisible(false);
     ui->label_2->setVisible(false);
    //textedit
     ui->User->setVisible(false);
     ui->Password->setVisible(false);
    //button
      ui->pushButton->setVisible(false);
    //scene


}

void login::on_pushButton_clicked()
{
    QString User=ui->User->text();
    QString Password=ui->Password->text();
   Invisible_login();
}
