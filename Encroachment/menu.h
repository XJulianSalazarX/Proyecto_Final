#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QGraphicsScene>
#include <QMessageBox>
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "login.h"
#include "multiplayer.h"

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

    void showMenu();

    short getLevel() const;

    Level1 *level1;
    Multiplayer *multiplayer;

    QString getUsername() const;
    void setUsername(const QString &value);

    short getCharacter() const;

    void setLevel(short value);

    bool getMult() const;

    void setCharacter(short value);

    void startTimer();

private slots:
    void on_play_clicked();

    void on_howToPLay_clicked();

    void on_settings_clicked();

    void on_level1_clicked();

    void on_level2_clicked();

    void on_level3_clicked();

    void on_play_2_clicked();

    void on_logOut_clicked();

    void on_start_clicked();

    void on_character1_clicked();

    void on_character2_clicked();

    void on_character3_clicked();

    void on_deleteProfile_clicked();

    void on_deleteProgress_clicked();

    void on_multiplayer_clicked();

    void on_top_clicked();

    void on_profile_clicked();

public slots:
    void on_back_clicked();
    void Music();

private:
    Ui::Menu *ui;
    QGraphicsScene *scene;
    Login *login;
    short level,character,song;
    QString username;
    bool mult;
    QMediaPlayer *sound;
    QTimer *timerSound;

};

#endif // MENU_H
