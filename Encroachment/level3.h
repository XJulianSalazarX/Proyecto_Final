#ifndef LEVEL3_H
#define LEVEL3_H

#include <QWidget>
#include <level1.h>

namespace Ui {
class Level3;
}

class Level3 : public Level1
{
    Q_OBJECT

public:
    explicit Level3(Level1 *parent = nullptr);
    ~Level3();

private:
    Ui::Level3 *ui;

public slots:
    void makeEnemies();
    void makeObstacles();
    void makeEnemies2();
    void makeObstacles2();
};

#endif // LEVEL3_H
