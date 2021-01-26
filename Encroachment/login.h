#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QString>
#include <QFile>
#include <fstream>
#include <QMessageBox>
#include <file.h>

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_singIn_clicked();

    void on_singUp_clicked();

    void on_back_clicked();

    void on_next_clicked();

private:
    Ui::Login *ui;
    QGraphicsScene *scene_login;
};

#endif // LOGIN_H
