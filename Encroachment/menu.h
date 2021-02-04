/**
  @file menu.h
  @version 1.0
  @title Class Menu
  @brief hereda QWidget de la librereria de Qt creator, y la clase file, esta clase
  representa el menu del juego encroachment.
  */
#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QGraphicsScene>
#include <QMessageBox>
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "login.h"
#include "multiplayer.h"

namespace Ui {
class Menu;
}

class Menu : public QWidget,public File
{
    Q_OBJECT

public:
    /**
     * @brief Menu, constructor de la clase menu.h.
     * @param parent
     */
    explicit Menu(QWidget *parent = nullptr);
    /**
     * @brief ~Menu, destructor de la clase menu.h.
     */
    ~Menu();
    /**
     * @brief Visible, hace visible a los QPussButoon´s ui->play, ui->profile,
     ui->top, ui->settings, ui->howToPlay y ui->multiplayer.
     */
    void Visible();
    /**
     * @brief Invisible, hace invisible a los QPussButoon´s ui->play, ui->profile,
     ui->top, ui->settings, ui->howToPlay y ui->multiplayer.
     */
    void Invisible();

    /**
     * @brief showMenu, cambia el fondo del ui->graphicsView y ejecuta la instancia
     Visible().
     */
    void showMenu();
    /**
     * @brief getLevel
     * @return retorna el valor del atributo level.
     */
    short getLevel() const;

    Level1 *level1;
    Multiplayer *multiplayer;

    /**
     * @brief getUsername
     * @return retorna el valor del atributo username.
     */
    QString getUsername() const;
    /**
     * @brief setUsername, a usernamese le asigna el QString value.
     * @param value, QString que se le asigna a username
     */
    void setUsername(const QString &value);
    /**
     * @brief getCharacter
     * @return retorna el valor del atributo character.
     */
    short getCharacter() const;
    /**
     * @brief setLevel, a level se le asigna el valor de value.
     * @param value, short que se le asigna a level.
     */
    void setLevel(short value);
    /**
     * @brief getMult
     * @return retorna el booleano del atributo multp.
     */
    bool getMult() const;
    /**
     * @brief setCharacter, a character se le asigna el valor de value.
     * @param value, short que se le asigna a level.
     */
    void setCharacter(short value);

    /**
     * @brief startTimer, inicia el QTimer timersound.
     */
    void startTimer();

private slots:
    void on_play_clicked();

    void on_howToPLay_clicked();

    void on_settings_clicked();

    void on_level1_clicked();

    void on_level2_clicked();

    void on_level3_clicked();

    void on_play_2_clicked();

    void on_logOut_clicked();

    void on_start_clicked();

    void on_character1_clicked();

    void on_character2_clicked();

    void on_character3_clicked();

    void on_deleteProfile_clicked();

    void on_deleteProgress_clicked();

    void on_multiplayer_clicked();

    void on_top_clicked();

    void on_profile_clicked();

public slots:
    void on_back_clicked();
    void Music();

private:
    Ui::Menu *ui;
    /**
     * @brief scene, instacia de la clase QGraphicsScene.
     */
    QGraphicsScene *scene;
    /**
     * @brief login, instacia de la clase Login.
     */
    Login *login;
    /**
     * @brief level, representa el nivel en el que se va ajugar.
     */
    /**
     * @brief character, seleccionar uno de los tres posibles personajes.
     */
    /**
     * @brief song, representa la cancion que va a sonar.
     */
    short level,character,song;
    /**
     * @brief username, recibe un QString ingresado por el usuario.
     */
    QString username;
    /**
     * @brief mult, si es verdadero es porque se va ajugar el multijugador,
      si es falso no se va a ejecutar el multijugador.
     */
    bool mult;
    /**
     * @brief sound, instacia de la clase QMediaPlayer
     */
    QMediaPlayer *sound;
    /**
     * @brief timerSound, esta conectado con el metodo Music de la clase menu.h.
     */
    QTimer *timerSound;

};

#endif // MENU_H
