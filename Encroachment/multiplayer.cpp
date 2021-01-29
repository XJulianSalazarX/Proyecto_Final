#include "multiplayer.h"
#include "ui_multiplayer.h"

Multiplayer::Multiplayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Multiplayer)
{
    ui->setupUi(this);
}

Multiplayer::~Multiplayer()
{
    delete ui;
}
