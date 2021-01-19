#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QGraphicsScene>
#include <QMessageBox>
#include "level1.h"

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();
    void Visible();
    void Invisible();

    short getLevel() const;

    Level1 *level1;

private slots:
    void on_play_clicked();

    void on_howToPLay_clicked();

    void on_settings_clicked();

    void on_level1_clicked();

    void on_level2_clicked();

    void on_level3_clicked();

    void on_play_2_clicked();

    void on_logOut_clicked();

public slots:
    void on_back_clicked();

private:
    Ui::Menu *ui;
    QGraphicsScene *scene;
    short level;
//    Level1 *level1;

};

#endif // MENU_H
