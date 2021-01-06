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
    ui->label->setVisible(false);
    ui->label_2->setVisible(false);
    ui->back->setVisible(false);
    ui->Username->setVisible(false);
    ui->Password->setVisible(false);
    ui->next->setVisible(false);
    ui->label_3->setVisible(false);
    ui->password_2->setVisible(false);


}

login::~login()
{
    delete ui;
}



void login::on_singIn_clicked()
{
   ui->singIn->setVisible(false);
   ui->singUp->setVisible(false);
   ui->label->setVisible(true);
   ui->label_2->setVisible(true);
   ui->back->setVisible(true);
   ui->Username->setVisible(true);
   ui->Password->setVisible(true);
   ui->next->setVisible(true);

}



void login::on_singUp_clicked()
{
    ui->singIn->setVisible(false);
    ui->singUp->setVisible(false);
    ui->label->setVisible(true);
    ui->label_2->setVisible(true);
    ui->back->setVisible(true);
    ui->Username->setVisible(true);
    ui->Password->setVisible(true);
    ui->next->setVisible(true);
    ui->label_3->setVisible(true);
    ui->password_2->setVisible(true);

}

void login::on_back_clicked()
{
    ui->label->setVisible(false);
    ui->label_2->setVisible(false);
    ui->back->setVisible(false);
    ui->Username->setVisible(false);
    ui->Password->setVisible(false);
    ui->next->setVisible(false);
    ui->singIn->setVisible(true);
    ui->singUp->setVisible(true);
    ui->label_3->setVisible(false);
    ui->password_2->setVisible(false);
}

void login::on_next_clicked()
{
    if (ui->password_2->isVisible()) {
        //comprobar que no este registrado
        if (ui->Username->text()=="" or ui->Password->text()=="") {
            QMessageBox::critical(this,"Error","Ingrese nombre de usuario y clave para continuar");
            ui->Username->setText("");
            ui->Password->setText("");
            ui->password_2->setText("");


                    return;
        }
        else if (ui->Password->text()!= ui->password_2->text()) {
            QMessageBox::critical(this,"Error","Las claves ingresadas no coinciden");
            ui->Username->setText("");
            ui->Password->setText("");
            ui->password_2->setText("");
                    return;
}
    }
    else{
    if (ui->Username->text()=="" or ui->Password->text()=="") {
        QMessageBox::critical(this,"Error","Ingrese nombre de usuario y clave para continuar");
        ui->Username->setText("");
        ui->Password->setText("");
                return;
    }
    }
}
