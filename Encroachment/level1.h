#ifndef LEVEL1_H
#define LEVEL1_H

#include <QWidget>
#include <QGraphicsScene>
#include "character.h"
#include "enemy.h"

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

private:
    Ui::Level1 *ui;
    QGraphicsScene *scene;
    Character *player;
    Enemy *enemy;

    QTimer *timerE;

public slots:
    void makeEnemies();
};

#endif // LEVEL1_H
