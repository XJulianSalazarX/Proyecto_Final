/**
  @file level1.h
  @version 1.0
  @title Class Level1
  @brief hereda QWidget de la librereria de Qt creator, esta clase
  representa el nivel 1 del juego encroachment.
  */
#ifndef LEVEL1_H
#define LEVEL1_H

#include <QWidget>
#include <QGraphicsScene>
#include "character.h"
#include "obstacle2.h"
#include "enemyshoots.h"
#include "bonus.h"
#include "boss.h"
#include "power.h"
#include "boss2.h"
#include <QMediaPlayer>

namespace Ui {
class Level1;
}

class Level1 : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Level1, constructor de la clase level1.h.
     * @param parent
     */
    explicit Level1(QWidget *parent = nullptr);
    /**
     * @brief ~Level1, destructor de la clase level1.h.
     */
    ~Level1();

    /**
     * @brief FocusPlayer, enfocar a player.
     */
    void FocusPlayer();
    /**
     * @brief playerPos
     * @return retorna un double que es la posición en y() de player.
     */
    double playerPos();
    /**
     * @brief playerPosX
     * @return retorna un double que es la posición en x() de player.
     */
    double playerPosX();
    int getObstacle();
    /**
     * @brief playerHealth, llama al método getHealth() de player y el valor
     es asignado a ui->progressBar.
     */
    void playerHealth();
    /**
     * @brief playerScore, suma el parametro increase al valor de ui->score,
     * el nuevo valor es asignado a ui->score.
     * @param increase
     */
    void playerScore(int increase);
    /**
     * @brief Final, se pasa al jefe final, en esta parte se cambia de la vista
     cenital a la vista horizontal.
     */
    void Final();
    /**
     * @brief BossHealth, llama al método getHealth() de boss o boos2 dependiendo
     del valor del atributo level de la clase menu.h y el valor es asignado a
     ui->progressBar_2.
     */
    void BossHealth();
    /**
     * @brief getPlayerHealth
     * @return retorna un double que es el valor de ui->progressBar.
     */
    double getPlayerHealth();
    /**
     * @brief returnMenu, se ejecuta en caso de que el atributo health de player
     llegue a 0, se ponen visibles los QPussButton´s ui->retry, ui->home y se muesra
     el puntaje obtenido.
     */
    void returnMenu();
    /**
     * @brief complete, se ejecuta en caso de que el atributo health de boss o boss2
     llegue a 0, se pone visible el QPussButton ui->home, y se muestra el puntaje
      obtenido.
     */
    void complete();
    /**
     * @brief changePower, Cambia el movimiento circular de power por el movimiento
     armónico simple.
     */
    void changePower();

protected:
    Ui::Level1 *ui;
    QGraphicsScene *scene;
    Character *player;
    Enemy *enemy;
    Obstacle *obs;
    EnemyShoots *enemy2;
    Obstacle2 *obs2;
    Bonus *bonus;
    Boss *boss;
    Power *power;
    Boss2 *boss2;

    QTimer *timerE;
    QTimer *timerB;
    QTimer *timerSound;

    int posx;
    bool isBoss;
    short song;

    QMediaPlayer *sound;

public slots:
    /**
     * @brief makeEnemies, genera una insancia de la clase Eemy.
     */
    void makeEnemies();
    /**
     * @brief makeObstacles, genera una instancia de la clase Obstacle.
     */
    void makeObstacles();
    /**
     * @brief makeEnemies2, genera una instancia de la clase EnemyShoots.
     */
    void makeEnemies2();
    /**
     * @brief makeObstacles2, genera una instancia de la clase Obstacle2.
     */
    void makeObstacles2();
    /**
     * @brief makeBonus, genera una instancia de la clase Bonus.
     */
    void makeBonus();
    /**
     * @brief Music, reproduce canciones de manera aleatoria.
     */
    void Music();


private slots:
    /**
     * @brief on_stop_clicked
     */
    void on_stop_clicked();
    /**
     * @brief on_cont_clicked
     */
    void on_cont_clicked();
    /**
     * @brief on_retry_clicked
     */
    void on_retry_clicked();
    /**
     * @brief on_home_clicked
     */
    void on_home_clicked();
};

#endif // LEVEL1_H
