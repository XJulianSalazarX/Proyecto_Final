#ifndef FILE_H
#define FILE_H

#include <QString>
#include <fstream>
#include <iostream>

using namespace std;
string LeerArchivo();
void SaveArchivo(string );

string Str_to_Binary(string );
string Binary_to_Str(string );

string decod(string );
string Cod(string );
string cambiar_decof(string );
string Cambiar_pos(string );

bool existUser(QString);
bool CheckPassword(QString,QString);
void adduser(QString, QString);
void deleteUSer(QString,QString);
void deleteScore(QString, QString);
void GoScore();

#endif // FILE_H
