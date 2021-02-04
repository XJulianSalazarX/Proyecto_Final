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

public:/**
     * @brief Multiplayer, constructor de la clase multiplayer.h.
     * @param parent
     */
    explicit Multiplayer(QWidget *parent = nullptr);
    /**
      *@brief ~Multiplayer, destructor de la clase multiplayer.h.
      */
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
    /**
     * @brief scene, instancia de la clase QGraphicsScene.
     */
    QGraphicsScene *scene;
    /**
     * @brief timer,
     */
    QTimer *timer;
    /**
     * @brief player, instancia de la clase Character.
     */
    Character *player;
    /**
     * @brief boss, instancia de la clase Boss.
     */
    Boss *boss;
    /**
     * @brief boss2, instancia de la clase Boss2.
     */
    Boss2 *boss2;
    /**
     * @brief power, instancia de la clase Power.
     */
    Power *power;  
    /**
     * @brief player1,
     */
    /**
     * @brief score1,
     */
    QString player1,score1;
    /**
     * @brief player2,
     */
    /**
     * @brief score2,
     */
    QString player2,score2;
    /**
     * @brief time1,
     */
    /**
     * @brief time2,
     */
    double time1,time2;
    /**
     * @brief level,
     */
    /**
     * @brief character,
     */
    short level,character;
    /**
     * @brief turn2,
     */
    /**
     * @brief boss_win,
     */
    bool turn2,boss_win;
    /**
     * @brief sound, instancia de la clase QMediaPlayer.
     */
    QMediaPlayer *sound;
    /**
     * @brief changeSound,
     */
    bool changeSound;
    /**
     * @brief timerSound,
     */
    QTimer *timerSound;

public slots:
    void time();
    void otherMusic();
};

#endif // MULTIPLAYER_H
