#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QString>
//#include <QChar>
#include <QFile>
#include <QDebug>
#include <fstream>
#include <QMessageBox>

using namespace std;


namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

    string LeerArchivo();
    void SaveArchivo(string );

    string Str_to_Binary(string );
    string Binary_to_Str(string );

    string decod(string );
    string Cod(string );
    string cambiar_decof(string );
    string Cambiar_pos(string );

    int existUser(QString);
    bool CheckPassword(QString,QString);
    void adduser(QString, QString);

private slots:
    void on_singIn_clicked();

    void on_singUp_clicked();

    void on_back_clicked();

    void on_next_clicked();

private:
    Ui::login *ui;
     QGraphicsScene *scene_login;
};

#endif // LOGIN_H
