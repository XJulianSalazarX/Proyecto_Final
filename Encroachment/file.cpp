#include "file.h"


void adduser(QString user, QString password)
{
string text;
string user_=user.toStdString();
string password_=password.toStdString();

 text=LeerArchivo();
 text=Str_to_Binary(text);
 text=decod( text);
 text=Binary_to_Str( text);

 text= text + user_+ ":"+password_+"\n"+"0:0:0"+"\n"+"0:0:0"+"\n"+"0:0:0"+"\n"+"0:0:0"+"\n";

 text=Str_to_Binary(text);
 text=Cod( text);
 text=Binary_to_Str( text);

 SaveArchivo(text);
}

void deleteUSer(QString user, QString password)
{
    string text;
    string text_new;

    if (CheckPassword(user,password)==true) {


     text=LeerArchivo();
     text=Str_to_Binary(text);
     text=decod( text);
     text=Binary_to_Str( text);



     int posUSer_initial=existUser(user);
     int posUser_final=0;
     int aux=posUSer_initial;

     for (int i=0;i<=4 ;) {
         posUser_final=text.find('\n',aux);
         aux= posUser_final+1;
         i+=1;
     }
     if(posUser_final==-1) text_new=text.substr(0,posUSer_initial-1);
     else {
         text_new=text.substr(0,posUSer_initial-1)+text.substr(posUser_final);

     }

     text_new=Str_to_Binary(text_new);
     text_new=Cod( text_new);
     text_new=Binary_to_Str( text_new);

     SaveArchivo(text_new);
    }
}

void deleteScore(QString user, QString password)
{

    string text;
    string text_new;
    string Password= password.toStdString();
    if (CheckPassword(user,password)==true) {


     text=LeerArchivo();
     text=Str_to_Binary(text);
     text=decod( text);
     text=Binary_to_Str( text);


     string score="\n0:0:0\n0:0:0\n0:0:0\n0:0:0";
     int posUser=existUser(user);
     int posPass_initial=text.find(Password,posUser)+password.length()+1;
     int posPass_final=0;
     int aux=posPass_initial;

     for (int i=0;i<4 ;) {
         posPass_final=text.find('\n',aux);
         aux= posPass_final+1;
         i+=1;
     }
     if(posPass_final==-1) text_new=text.substr(0,posPass_initial-1)+score;
     else {
         text_new=text.substr(0,posPass_initial-1)+score+text.substr(posPass_final);

     }

     text_new=Str_to_Binary(text_new);
     text_new=Cod( text_new);
     text_new=Binary_to_Str( text_new);

     SaveArchivo(text_new);
    }

}


int existUser(QString user)
{
    string user_=user.toStdString();

   string texto;
   texto=LeerArchivo();
   texto=Str_to_Binary(texto);
   texto=decod(texto);
   texto=Binary_to_Str(texto);

   int exist=texto.find(user_);
   int num=user_.length();
   num=num+exist;

   char x=texto[num];
   char y=texto[exist-1];
   if (x!=':')exist=-1;
   if (y!='\n')exist=-1;

   return exist;
}
bool CheckPassword(QString user, QString password){

    string texto;
    string password_=password.toStdString();

    texto=LeerArchivo();
    texto=Str_to_Binary(texto);
    texto=decod(texto);
    texto=Binary_to_Str(texto);

    int posUser=existUser(user);
    int num=user.length();
     int num2=password.length();
    posUser=posUser+num-1;
    int posPass=texto.find(password_,posUser);
    char y=texto[posPass+num2];
    num=(posPass-posUser)-1;
    string Check=texto.substr(posUser+1,num);
    if(Check==":" and y=='\n') return true;

    else {
        return false;
    }
}


string LeerArchivo()
{
    string texto,linea;
    fstream lectura;

    lectura.open("users.dat",fstream::in|fstream::binary);
    if(lectura.fail()){
        cout<<"No se pudo abrir el archivo." << endl;
        exit(1);
    }
    while(lectura.good()){
        linea=lectura.get();
        texto.append(linea);
    }
    lectura.close();
    texto.pop_back();
    return texto;

}

void SaveArchivo( string texto)
{
    fstream archivobinario;
    archivobinario.open("users.dat",fstream::out|fstream::binary);

    if(archivobinario.fail()){
        cout<<"No se pudo abrir el archivo."<<endl;
        exit(1);
    }
    archivobinario<<texto;
    archivobinario.close();
}



string Str_to_Binary(string texto)
{
    string binario;
    for(unsigned long long int i=0; i<texto.length(); i++){
        for(int j=0;j<8;j++) binario.push_back(char((((texto[i]<<j)&(0x80))/128)+48));
    }
    return binario;
}

string Binary_to_Str(string binario)
{
    string caracter,texto;
    for(int i=0; i<int(binario.length());i+=8){
        caracter = binario.substr(i,8);
        caracter = stoi(caracter, nullptr, 2);
        texto.append(caracter);
    }
    return texto;
}

string Cod(string texto)
{
    int semilla=4;
    string parte,codificado;
    if(semilla < int(texto.length()))  {
        for(unsigned long long int i=0;i<texto.length();i+=semilla){
            if(i+semilla<texto.length())
                parte = texto.substr(i,semilla);
            else
                parte = texto.substr(i);
            codificado.append(Cambiar_pos(parte));
            parte.clear();
        }
    }
    else
        codificado.append(Cambiar_pos(texto));
    return codificado;
}

string Cambiar_pos(string binario)
{
    string binarioCodif;
    binarioCodif += binario[binario.length()-1];
    for(int i=0; i<int(binario.length())-1; i++){
        binarioCodif += binario[i];
    }
    return binarioCodif;
}

string decod(string texto)
{
    int semilla=4;
    string parte,decodificado;
    if(semilla < int(texto.length()))  {
        for(unsigned long long int i=0;i<texto.length();i+=semilla){
            if(i+semilla<texto.length())
                parte = texto.substr(i,semilla);
            else
                parte = texto.substr(i);
            decodificado.append(cambiar_decof(parte));

            parte.clear();
        }
    }
    else
        decodificado.append(cambiar_decof(texto));

    return decodificado;
}

string cambiar_decof(string binario)
{
    string binario_decof;
    binario_decof += binario[1];
    for(int i=2; i<int(binario.length()); i++){
        binario_decof += binario[i];
    }
    binario_decof += binario[0];
    return binario_decof;
}

