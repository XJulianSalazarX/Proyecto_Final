/**
  @file level2.h
  @version 1.0
  @title Class Level2
  @brief hereda la clase Level1, esta clase
  representa el nivel 2 del juego encroachment.
  */
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
    /**
     * @brief Level2, constructor de la clase level2.h.
     * @param parent
     */
    explicit Level2(Level1 *parent = nullptr);
    /**
     * @brief ~Level2, destructor de la clase level2.h.
     */
    ~Level2();

private:
    Ui::Level2 *ui;

public slots:
    /**
     * @brief makeEnemies, genera dos insancias de la clase Eemy.
     */
    void makeEnemies();
    /**
     * @brief makeObstacles, genera dos instancias de la clase Obstacle.
     */
    void makeObstacles();
    /**
     * @brief makeEnemies2, genera dos instancias de la clase EnemyShoots.
     */
    void makeEnemies2();
    /**
     * @brief makeObstacles2, genera dos instancias de la clase Obstacle2.
     */
    void makeObstacles2();
};

#endif // LEVEL2_H
