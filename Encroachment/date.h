#ifndef DATE_H
#define DATE_H
#include <QString>
#include <fstream>

using namespace std;

class date
{
public:
    date();

    void LeerArchivo();
    void SaveArchivo( string );

    string Str_to_Binary(string );
    string Binary_to_Str(string );

   string decod( string );
   string Cod(string );

    void adduser(QString, QString);

};

#endif // DATE_H
