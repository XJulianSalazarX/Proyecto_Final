#ifndef LEVEL1_H
#define LEVEL1_H

#include <QWidget>
#include <QGraphicsScene>
#include "character.h"
#include "obstacle2.h"
#include "enemyshoots.h"
#include "bonus.h"
#include "boss.h"
#include "power.h"

namespace Ui {
class Level1;
}

class Level1 : public QWidget
{
    Q_OBJECT

public:
    explicit Level1(QWidget *parent = nullptr);
    ~Level1();

    void FocusPlayer();
    double playerPos();
    int getObstacle();
    void playerHealth();
    void playerScore(int increase);
    void Final();
    void BossHealth();
    double getPlayerHealth();
    void returnMenu();
    void complete();

protected:
    Ui::Level1 *ui;
    QGraphicsScene *scene;
    Character *player;
    Enemy *enemy;
    Obstacle *obs;
    EnemyShoots *enemy2;
    Obstacle2 *obs2;
    Bonus *bonus;
    Boss *boss;
    Power *power;

    QTimer *timerE;
    QTimer *timerB;

    int posx;
    bool isBoss;

public slots:
    void makeEnemies();
    void makeObstacles();
    void makeEnemies2();
    void makeObstacles2();
    void makeBonus();

private slots:
    void on_stop_clicked();
    void on_cont_clicked();
    void on_retry_clicked();
    void on_home_clicked();
};

#endif // LEVEL1_H
