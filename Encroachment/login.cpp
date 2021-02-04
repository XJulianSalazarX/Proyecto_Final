#include "login.h"
#include "ui_login.h"
#include "menu.h"
#include <QDebug>

extern Menu *menu;

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    setWindowTitle("Encroachment");

    this->setMinimumSize(width(),height());
    this->setMaximumSize(width(),height());
    scene_login = new QGraphicsScene();
    ui->graphicsView->setScene(scene_login);
    ui->graphicsView->setFixedSize(width(),height()-20);
    ui->graphicsView->setSceneRect(0,0,width(),height()-20);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/images/fondo.jpg").scaled(1280,720)));
    ui->label->setVisible(false);
    ui->label_2->setVisible(false);
    ui->back->setVisible(false);
    ui->Username->setVisible(false);
    ui->Password->setVisible(false);
    ui->next->setVisible(false);
    ui->label_3->setVisible(false);
    ui->password_2->setVisible(false);
}

Login::~Login()
{
    delete ui;
}

void Login::on_singIn_clicked()
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

void Login::on_singUp_clicked()
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

void Login::on_back_clicked()
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
    ui->Username->setText("");
    ui->Password->setText("");
    ui->password_2->setText("");
}

void Login::on_next_clicked()
{
    QString user=ui->Username->text();
    QString password=ui->Password->text();

    if (ui->password_2->isVisible()) {

        if (ui->Username->text()=="" or ui->Password->text()=="") {
            QMessageBox::critical(this,"Error","Ingrese nombre de usuario y clave para continuar.");
            ui->Username->setText("");
            ui->Password->setText("");
            ui->password_2->setText("");
            return;
        }
        else if(existUser(ui->Password->text())){
            QMessageBox::critical(this,"Error","Clave no valida.");
            ui->Username->setText("");
            ui->Password->setText("");
            ui->password_2->setText("");
            return;
        }
        else if(ui->Password->text()== ui->Username->text()){
            QMessageBox::critical(this,"Error","el usuario y clave no pueden ser iguales.");
            ui->Username->setText("");
            ui->Password->setText("");
            ui->password_2->setText("");
            return;
        }
        else if(!ValidUandP(ui->Username->text())){
            QMessageBox::critical(this,"Error","Usuario y clave no deben llevar : o \\n o \\r");
            ui->Username->setText("");
            ui->Password->setText("");
            ui->password_2->setText("");
            return;
        }
        else if(!ValidUandP(ui->Password->text())){
            QMessageBox::critical(this,"Error","Usuario y clave no deben llevar : o \\n o \\r");
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

        else if (existUser(user)==false) {
            adduser(user,password);
            //pasar a otra pantalla, porque ya se registrara
            menu->setUsername(ui->Username->text());
            menu->show();
            menu->showMenu();
            delete this;
            return;
        }
        else if (existUser(user)==true) {
            QMessageBox::critical(this,"Error","El usuario ya existe");
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
        else if (existUser(user)==false) {
            QMessageBox::critical(this,"Error","El usuario no existe");
            ui->Username->setText("");
            ui->Password->setText("");
            return;
        }


        else if (CheckPassword(user,password)==false){
            QMessageBox::critical(this,"Error","clave incorrecta");
            ui->Username->setText("");
            ui->Password->setText("");
            return;
        }
        else if(CheckPassword(user,password)==true) {
            //pasar a otra pantalla, porque ya inicio sesion
            qDebug() << "Usuario y clave correctas";
            menu->setUsername(ui->Username->text());
            menu->show();
            menu->showMenu();
            delete this;
            return;
        }
        return;
    }
}
