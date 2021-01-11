#ifndef LEVEL1_H
#define LEVEL1_H

#include <QWidget>
#include <QGraphicsScene>
#include "character.h"
#include "enemy.h"
#include "obstacle.h"
#include "enemyshoots.h"
#include "bonus.h"

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
    Obstacle *obs;

private:
    Ui::Level1 *ui;
    QGraphicsScene *scene;
    Character *player;
    Enemy *enemy;
    EnemyShoots *enemy2;
    Bonus *bonus;

    QTimer *timerE;
    QTimer *timerO;
    QTimer *timerE2;
    QTimer *timerB;

public slots:
    void makeEnemies();
    void makeObstacles();
    void makeEnemies2();
    void makeBonus();
};

#endif // LEVEL1_H
