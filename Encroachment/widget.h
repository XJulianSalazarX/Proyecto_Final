#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include "character.h"
#include "enemy.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QTimer *T_enemies;

private:
    Ui::Widget *ui;
    QGraphicsScene *scene;
    Character *player;

public slots:
    void Enemies();
};
#endif // WIDGET_H
