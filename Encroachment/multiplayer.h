#ifndef MULTIPLAYER_H
#define MULTIPLAYER_H

#include <QWidget>
#include <QGraphicsScene>
#include <QMessageBox>
#include <file.h>
#include <QTimer>
#include "character.h"
#include "boss.h"
#include "boss2.h"
#include "power.h"
#include <QMediaPlayer>
#include <file.h>


namespace Ui {
class Multiplayer;
}

class Multiplayer : public QWidget, public File
{
    Q_OBJECT

public:
    explicit Multiplayer(QWidget *parent = nullptr);
    ~Multiplayer();

    void selectLevel();
    void startGame();

    double getPlayerHealth();
    void playerHealth();
    double playerPos();
    double playerPosX();
    void BossHealth();
    void changePower();
    void endTurn();
    void showResult();

    void setBoss_win(bool value);

private slots:
    void on_next_clicked();

    void on_level1_clicked();

    void on_level2_clicked();

    void on_level3_clicked();

    void on_character1_clicked();

    void on_character2_clicked();

    void on_character3_clicked();

    void on_back_clicked();

private:
    Ui::Multiplayer *ui;
    QGraphicsScene *scene;
    QTimer *timer;
    Character *player;
    Boss *boss;
    Boss2 *boss2;
    Power *power;
    QString player1,score1;
    QString player2,score2;
    double time1,time2;
    short level,character;
    bool turn2,boss_win;
    QMediaPlayer *sound;
    bool changeSound;
    QTimer *timerSound;

public slots:
    void time();
    void otherMusic();
};

#endif // MULTIPLAYER_H
