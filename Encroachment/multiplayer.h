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


namespace Ui {
class Multiplayer;
}

class Multiplayer : public QWidget
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
    QString player1,time1;
    QString player2,time2;
    short level,character;
};

#endif // MULTIPLAYER_H
