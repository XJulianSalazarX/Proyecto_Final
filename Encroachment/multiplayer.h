#ifndef MULTIPLAYER_H
#define MULTIPLAYER_H

#include <QWidget>

namespace Ui {
class Multiplayer;
}

class Multiplayer : public QWidget
{
    Q_OBJECT

public:
    explicit Multiplayer(QWidget *parent = nullptr);
    ~Multiplayer();

private:
    Ui::Multiplayer *ui;
};

#endif // MULTIPLAYER_H
