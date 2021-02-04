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

class Login : public QMainWindow, public File
{
    Q_OBJECT

public:
    /**
     * @brief Login, constructor de la clase login.h.
     * @param parent
     */
    explicit Login(QWidget *parent = nullptr);
    /**
      *@brief ~Login, destructor de la clase login.h.
      */
    ~Login();

private slots:
    void on_singIn_clicked();

    void on_singUp_clicked();

    void on_back_clicked();

    void on_next_clicked();

private:
    Ui::Login *ui;
    /**
     * @brief scene_login, instacia de la clase QGraphicsScene.
     */
    QGraphicsScene *scene_login;
};

#endif // LOGIN_H
