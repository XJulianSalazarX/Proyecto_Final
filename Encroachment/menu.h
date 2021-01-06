#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QGraphicsScene>

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

private slots:
    void on_play_clicked();

    void on_howToPLay_clicked();

    void on_settings_clicked();

    void on_back_clicked();

private:
    Ui::Menu *ui;
    QGraphicsScene *scene;

};

#endif // MENU_H
