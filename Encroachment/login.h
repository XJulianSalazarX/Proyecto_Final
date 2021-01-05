#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QString>



namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

    void Invisible_login();

private slots:
    void on_pushButton_clicked();

private:
    Ui::login *ui;
     QGraphicsScene *scene_login;
};

#endif // LOGIN_H
