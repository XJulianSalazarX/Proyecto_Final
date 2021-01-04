#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include "character.h"
#include "enemy.h"
#include "obstacle.h"
#include "bonus.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QTimer *t_enemies;
    QTimer *t_obstacles;
    QTimer *t_bonus;

private:
    Ui::Widget *ui;
    QGraphicsScene *scene;
    Character *player;
    Enemy *enemy;
    Obstacle *obs;
    Bonus *bonus;

public slots:
    void Enemies();
    void respawn();
    void CreateBonus();
};
#endif // WIDGET_H
