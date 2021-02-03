/**
  @file level3.h
  @version 1.0
  @title Class Level3
  @brief hereda la clase Level1, esta clase
  representa el nivel 3 del juego encroachment.
  */
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
    /**
     * @brief Level3, constructor de la clase level3.h.
     * @param parent
     */
    explicit Level3(Level1 *parent = nullptr);
    /**
     * @brief ~Level3, destructor de la clase level3.h.
     */
    ~Level3();

private:
    Ui::Level3 *ui;

public slots:
    /**
     * @brief makeEnemies, genera tres insancias de la clase Eemy.
     */
    void makeEnemies();
    /**
     * @brief makeObstacles, genera tres instancias de la clase Obstacle.
     */
    void makeObstacles();
    /**
     * @brief makeEnemies2, genera tres instancias de la clase EnemyShoots.
     */
    void makeEnemies2();
    /**
     * @brief makeObstacles2, genera tres instancias de la clase Obstacle2.
     */
    void makeObstacles2();
};

#endif // LEVEL3_H
