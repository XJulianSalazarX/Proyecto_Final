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
}

void Login::on_next_clicked()
{
    QString user=ui->Username->text();
    QString password=ui->Password->text();

    if (ui->password_2->isVisible()) {

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

        else if (existUser(user)==-1) {
            adduser(user,password);
            //pasar a otra pantalla, porque ya se registrara
            menu->setUsername(ui->Username->text());
            menu->show();
            menu->showMenu();
            delete this;
            return;
        }
        else if (existUser(user)!=-1) {
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

//manejo de archivos



void Login::adduser(QString user, QString password)
{
string text;
string user_=user.toStdString();
string password_=password.toStdString();

 text=LeerArchivo();
 text=Str_to_Binary(text);
 text=decod( text);
 text=Binary_to_Str( text);

 text= text + user_+ ":"+password_+"\n"+"0:0:0"+"\n"+"0:0:0"+"\n"+"0:0:0"+"\n"+"0:0:0"+"\n";

 text=Str_to_Binary(text);
 text=Cod( text);
 text=Binary_to_Str( text);

 SaveArchivo(text);
}


bool Login::existUser(QString user)
{
   qDebug() << "Comprobar usuario";
   string texto,user_;
   texto=LeerArchivo();
   texto=Str_to_Binary(texto);
   texto=decod(texto);
   texto=Binary_to_Str(texto);

   qDebug() << texto.length();

   int exist=texto.find(user.toStdString());
   qDebug() << exist;
   user_ = texto.substr(exist,user.length());
   qDebug() << QString::fromStdString(user_) << " = " << user;

   if(user.toStdString() == user_) return true;
   else return false;
//   int num=user_.length();
//   num=num+exist;



//   char x=texto[num];
//   char y=texto[exist-1];
//   if (x!=':')exist=-1;
//   if (y!='\n')exist=-1;

//   return exist;
}
bool Login::CheckPassword(QString user, QString password){

    qDebug() << "Comprobar contraseña";
    string texto;

    texto=LeerArchivo();
    texto=Str_to_Binary(texto);
    texto=decod(texto);
    texto=Binary_to_Str(texto);

    qDebug() << QString::fromStdString(texto);

    //int posUser=existUser(user);
    int posUser = texto.find(user.toStdString());
    qDebug() << posUser;

    posUser=posUser+user.length();
    qDebug() << posUser;

    string check = texto.substr(posUser+1,password.size());

    qDebug() << QString::fromStdString(check);

    if(password.toStdString() == check) return true;
    else return false;
}


string Login::LeerArchivo()
{
    string texto,linea;
    fstream lectura;

    lectura.open("users.dat",fstream::in|fstream::binary);
    if(lectura.fail()){
        cout<<"No se pudo abrir el archivo." << endl;
        exit(1);
    }
    while(lectura.good()){
        linea=lectura.get();
        texto.append(linea);
    }
    lectura.close();
    texto.pop_back();
    return texto;

}

void Login::SaveArchivo( string texto)
{
    fstream archivobinario;
    archivobinario.open("users.dat",fstream::out|fstream::binary);

    if(archivobinario.fail()){
        cout<<"No se pudo abrir el archivo."<<endl;
        exit(1);
    }
    archivobinario<<texto;
    archivobinario.close();
}



string Login::Str_to_Binary(string texto)
{
    string binario;
    for(unsigned long long int i=0; i<texto.length(); i++){
        for(int j=0;j<8;j++) binario.push_back(char((((texto[i]<<j)&(0x80))/128)+48));
    }
    return binario;
}

string Login::Binary_to_Str(string binario)
{
    string caracter,texto;
    for(int i=0; i<int(binario.length());i+=8){
        caracter = binario.substr(i,8);
        caracter = stoi(caracter, nullptr, 2);
        texto.append(caracter);
    }
    return texto;
}

string Login::Cod(string texto)
{
    int semilla=4;
    string parte,codificado;
    if(semilla < int(texto.length()))  {
        for(unsigned long long int i=0;i<texto.length();i+=semilla){
            if(i+semilla<texto.length())
                parte = texto.substr(i,semilla);
            else
                parte = texto.substr(i);
            codificado.append(Cambiar_pos(parte));
            parte.clear();
        }
    }
    else
        codificado.append(Cambiar_pos(texto));
    return codificado;
}

string Login::Cambiar_pos(string binario)
{
    string binarioCodif;
    binarioCodif += binario[binario.length()-1];
    for(int i=0; i<int(binario.length())-1; i++){
        binarioCodif += binario[i];
    }
    return binarioCodif;
}

string Login::decod(string texto)
{
    int semilla=4;
    string parte,decodificado;
    if(semilla < int(texto.length()))  {
        for(unsigned long long int i=0;i<texto.length();i+=semilla){
            if(i+semilla<texto.length())
                parte = texto.substr(i,semilla);
            else
                parte = texto.substr(i);
            decodificado.append(cambiar_decof(parte));

            parte.clear();
        }
    }
    else
        decodificado.append(cambiar_decof(texto));

    return decodificado;
}

string Login::cambiar_decof(string binario)
{
    string binario_decof;
    binario_decof += binario[1];
    for(int i=2; i<int(binario.length()); i++){
        binario_decof += binario[i];
    }
    binario_decof += binario[0];
    return binario_decof;
}
