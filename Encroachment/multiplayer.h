/**
  @file multiplayer.h
  @version 1.0
  @title Class Multiplayer
  @brief hereda QWidget de la librereria de Qt creator, y la clase file, esta clase
  se usa para el multijugador del juego.
  */
#ifndef MULTIPLAYER_H
#define MULTIPLAYER_H

#include <QWidget>
#include <QGraphicsScene>
#include <QMessageBox>
#include <file.h>
#include <QTimer>
#include "character.h"
#include "boss.h"
#include "boss2.h"
#include "power.h"
#include <QMediaPlayer>
#include <file.h>


namespace Ui {
class Multiplayer;
}

class Multiplayer : public QWidget, public File
{
    Q_OBJECT

public:/**
     * @brief Multiplayer, constructor de la clase multiplayer.h.
     * @param parent
     */
    explicit Multiplayer(QWidget *parent = nullptr);
    /**
      *@brief ~Multiplayer, destructor de la clase multiplayer.h.
      */
    ~Multiplayer();

    /**
     * @brief selectLevel, seleccionar entre los tres niveles del multijugador.
     */
    void selectLevel();
    /**
     * @brief startGame, iniciar enfrentamiento contra el jefe seleccionado
     */
    void startGame();
    /**
     * @brief getPlayerHealth
     * @return retorna un double que es el valor de ui->progressBar.
     */
    double getPlayerHealth();
    /**
     * @brief playerHealth, llama al método getHealth() de player y el valor
     es asignado a ui->progressBar.
     */
    void playerHealth();
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
    /**
     * @brief BossHealth, llama al método getHealth() de boss o boos2 dependiendo
     del valor del atributo level de la clase menu.h y el valor es asignado a
     ui->progressBar_2.
     */
    void BossHealth();
    /**
     * @brief changePower, Cambia el movimiento circular de power por el movimiento
     armónico simple.
     */
    void changePower();
    /**
     * @brief endTurn, pasa de jugar el primer jugador, a jugar el segundo
     */
    void endTurn();
    /**
     * @brief showResult, muestra los resultados obtenidos por ambos jugadores
     */
    void showResult();
    /**
     * @brief setBoss_win
     * @param value, le asigna a Boss_win el booleano de value
     */
    void setBoss_win(bool value);

private slots:
    void on_next_clicked();

    void on_level1_clicked();

    void on_level2_clicked();

    void on_level3_clicked();

    void on_character1_clicked();

    void on_character2_clicked();

    void on_character3_clicked();

    void on_back_clicked();

private:
    Ui::Multiplayer *ui;
    /**
     * @brief scene, instancia de la clase QGraphicsScene.
     */
    QGraphicsScene *scene;
    /**
     * @brief timer, se conecta con la función time().
     */
    QTimer *timer;
    /**
     * @brief player, instancia de la clase Character.
     */
    Character *player;
    /**
     * @brief boss, instancia de la clase Boss.
     */
    Boss *boss;
    /**
     * @brief boss2, instancia de la clase Boss2.
     */
    Boss2 *boss2;
    /**
     * @brief power, instancia de la clase Power.
     */
    Power *power;  
    /**
     * @brief player1, qstring que representa el jugador 1.
     */
    /**
     * @brief score1, qstring que representa el puntaje del jugador 1.
     */
    QString player1,score1;
    /**
     * @brief player2, qstring que representa el jugador 2.
     */
    /**
     * @brief score2, qstring que representa el puntaje del jugador 2.
     */
    QString player2,score2;
    /**
     * @brief time1, double que representa el puntaje del jugador 1.
     */
    /**
     * @brief time2, double que representa el puntaje del jugador 2.
     */
    double time1,time2;
    /**
     * @brief level, representa el nivel en el que se va ajugar.
     */
    /**
     * @brief character, seleccionar uno de los tres posibles personajes.
     */
    short level,character;
    /**
     * @brief turn2, si turn2 es falso, es turno del jugador 1, de lo contrario
     es turno del jugador 2
     */
    /**
     * @brief boss_win, si es verdadero el atributo health de player (instancia de la
      clase Character es 0)
     */
    bool turn2,boss_win;
    /**
     * @brief sound, instancia de la clase QMediaPlayer.
     */
    QMediaPlayer *sound;
    /**
     * @brief changeSound, dependiendo si es verdade o falso se reproduce una canción
     */
    bool changeSound;
    /**
     * @brief timerSound, se conecta con la funicón other music.
     */
    QTimer *timerSound;

public slots:
    /**
     * @brief time, suma más 0.1 a time1 o time2 dependiendo de si turn2 es falso
     o verdadero.
     */
    void time();
    /**
     * @brief otherMusic, reproduce una canción u otra dependiendo de la variable
     changeSound.
     */
    void otherMusic();
};

#endif // MULTIPLAYER_H
