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

private:
    Ui::Level2 *ui;
};

#endif // LEVEL2_H
