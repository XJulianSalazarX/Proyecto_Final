#ifndef LEVEL1_H
#define LEVEL1_H

#include <QWidget>
#include <QGraphicsScene>
#include "character.h"
#include "obstacle2.h"
#include "enemyshoots.h"
#include "bonus.h"
#include <math.h>
#include "boss.h"

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
    void Final();
    void BossHealth();
    double getPlayerHealth();

private:
    Ui::Level1 *ui;
    QGraphicsScene *scene;
    Character *player;
    Enemy *enemy;
    Obstacle *obs;
    EnemyShoots *enemy2;
    Obstacle2 *obs2;
    Bonus *bonus;
    Boss *boss;

    QTimer *timerE;
    QTimer *timerO;
    QTimer *timerE2;
    QTimer *timerO2;
    QTimer *timerB;

    int posx;

public slots:
    void makeEnemies();
    void makeObstacles();
    void makeEnemies2();
    void makeObstacles2();
    void makeBonus();
};

#endif // LEVEL1_H
