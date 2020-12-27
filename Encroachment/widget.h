#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include "character.h"
#include "obstacle.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
public slots:
    void respawn();

private:
    Ui::Widget *ui;
    QGraphicsScene *scene;
    Character *player;
    obstacle *muro;

};
#endif // WIDGET_H
