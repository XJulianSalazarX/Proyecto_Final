#ifndef LEVEL2_H
#define LEVEL2_H

#include <QWidget>
#include <level1.h>

namespace Ui {
class Level2;
}

class Level2 : public Level1
{
    Q_OBJECT

public:
    explicit Level2(Level1 *parent = nullptr);
    ~Level2();

//    void Final();
//    void BossHealth();

private:
    Ui::Level2 *ui;

public slots:
    void makeEnemies();
    void makeObstacles();
    void makeEnemies2();
    void makeObstacles2();

//private slots:
//    void on_stop_clicked();
//    void on_cont_clicked();
};

#endif // LEVEL2_H
