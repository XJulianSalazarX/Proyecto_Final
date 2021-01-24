#include "level2.h"
#include "ui_level2.h"

Level2::Level2(Level1 *parent) :
    Level1(parent),
    ui(new Ui::Level2)
{
    ui->setupUi(this);
    scene->setBackgroundBrush(QPixmap(":/images/level2.1.jpg"));
}

Level2::~Level2()
{
    delete ui;
}
