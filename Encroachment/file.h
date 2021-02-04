/**
  @file file.h
  @version 1.0
  @title Class File
  @brief Clase usada para el manejo de archivos.
  */
#ifndef FILE_H
#define FILE_H

#include <QString>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class File
{
public:
    /**
     * @brief LeerArchivo, lee el archivo users.dat que contiene toda la informacion de los
     usuarios.
     * @return un string con la informasion del archivo users.dat.
     */
    string LeerArchivo();
    /**
     * @brief SaveArchivo, guarda en el archivo users.dat la informacion modificada
     de acuerdo a las interacciones del usuario durante el uso del juego.
     * @param texto, string que contiene la nueva informacion de los usuarios.
     */
    void SaveArchivo(string texto );
    /**
     * @brief Str_to_Binary, convierte un string con caracteres en codigo
     assci a un string en sistema binario.
     * @param texto, string de caracteres en codigo assci.
     * @return un string en sistema binario.
     */
    string Str_to_Binary(string texto);
    /**
     * @brief Binary_to_Str, convierte un estring en sistema binario a un estring con caracteres
      en codigo assci.
     * @param binario, string en sistema binario.
     * @return string de caracteres en codigo assci.
     */
    string Binary_to_Str(string binario);
    /**
     * @brief decod, recibe un string en sistema binario que esta codificado
      y hace uso del metodo cambiar_decof de la clase file.h.
     * @param texto, string  en sistema binario codificado.
     * @return un string con  en sistema binario decodificado.
     */
    string decod(string texto );
    /**
     * @brief Cod, recibe un string en sistema binario que esta decodificado
      y hace hace uso del metodo cambiar_pos de la clase file.h.
     * @param texto, string  en sistema binario decodificado.
     * @return un string  en sistema binario codificado.
     */
    string Cod(string texto);
    /**
     * @brief cambiar_decof, recibe un string en sistema binario y lo decodifica.
     * @param binario, string en sistema binario codificado.
     * @return string en sistema binario decodificado
     */
    string cambiar_decof(string binario);
    /**
     * @brief Cambiar_pos, recibe un string en sistema binario y lo codifica.
     * @param binario, string en sistema binario decodificado.
     * @return un string en sistema binario codificado.
     */
    string Cambiar_pos(string binario);
    /**
     * @brief existUser, verifica que el Qstring Username de la clase login.h
      ingresado por el usuario exista.
     * @param user, QString que se toma del atributo Username de la clase login.h.
     * @return un booleano, si es verdadero el usuario existe,
      si es falso el usuario no esta registrado.
     */
    bool existUser(QString user);
    /**
     * @brief CheckPassword, verifica que el Qstring Password ingresado por el usuario coincida con el Qstring Username
      de la clase login.h tambien ingresado por el usuario.
      ingresado por el usuario.
     * @param user, QString que se toma del atributo Username de la clase login.h.
     * @param password, Qstring que se toma del atributo Password de la clase login.h.
     * @return un booleano, si es verdadero la clave es correta, si es falso la clave es incorrecta.
     */
    bool CheckPassword(QString user,QString password);
    /**
     * @brief adduser, agrega la informacion nueva de un usuario al final del archivo users.dat.
     * @param user, QString que se toma del atributo Username de la clase login.h.
     * @param password, QString que se toma del atributo Password de la clase login.h.
     */
    void adduser(QString user, QString password);
    /**
     * @brief deleteUSer, elimina toda la informacion del usuario que esta en el archivo users.dat.
     * @param user, QString que se toma del atributo Username de la clase login.h.
     */
    void deleteUSer(QString user);
    /**
     * @brief deleteScore, elimina toda la informacion sobre el puntaje del usuario que esta en el archivo users.dat.
     * @param user, QString que se toma del atributo Username de la clase login.h.
     */
    void deleteScore(QString user);
    /**
     * @brief GoScore, modifica el archivo users.dat con los nuevos puntajes del usuario.
     * @param user, QString que se toma del atributo Username de la clase login.h.
     * @param Score, QString que se toma del atributo Score de la clase level1.h.
     * @param level, entero que se toma del atributo level de la clase menu.h.
     */
    void GoScore(QString user, QString Score,int level);
    /**
     * @brief CheckLevel, verifica si el usuario ya completo el nivel anterior al seleccionado.
     * @param user, QString que se toma del atributo Username de la clase login.h.
     * @param level, entero que se toma del atributo level de la clase menu.h.
     * @return un booleano, si es verdadero ya paso el nivel anterior, si es falso el nivel esta bloqueado
     debido a que el anterior no lo ha pasado.
     */
    bool CheckLevel(QString user,int level );
    /**
     * @brief ValidUandP, verifica que el usuario o clave no tengan ":" y '\n' para evitar conflictos en el trabajo
     con el archivo users.dat.
     * @param user_pass, QString que se toma del atributo Username o Password de la clase login.h.
     * @return un booleano, si es verdadero la clave o el usuario complen con las condiciones, si es falso no se puede registrar.
     */
    bool ValidUandP(QString user_pass);
    /**
     * @brief UpdateLevel, al completar el nivel se modifica en el archivo users.dat esa informacion del usuario.
     * @param user, QString que se toma del atributo Username de la clase login.h.
     * @param level, entero que se toma del atributo level de la clase menu.h.
     */
    void UpdateLevel(QString user, int level);
    /**
     * @brief usersName, recorre el archivo users.dat para ingresar en cada posicion del vector un usuario registrado.
     * @return vector<string> con todos los usuarios registrados.
     */
    vector<string> usersName();
    /**
     * @brief playerScore, recorre el archivo users.dat para ingresar en cada posicion del vector el puntaje del usuario.
     * @param user_, QString que se toma del atributo Username de la clase login.h.
     * @return un vector<string> con todos los puntajes del usuario.
     */
    vector<string> playerScore(QString user_);
};

#endif // FILE_H
