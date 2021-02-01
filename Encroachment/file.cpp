#include "file.h"
#include <QDebug>


void adduser(QString user, QString password)
{
    string text;
    string user_=user.toStdString();
    string password_=password.toStdString();

    text=LeerArchivo();
    text=Str_to_Binary(text);
    text=decod( text);
    text=Binary_to_Str( text);

    text= text + user_+ ":"+password_+"\r\n"+"0:0:0"+"\r\n"+"0:0:0"+"\r\n"+"0:0:0"+"\r\n"+"0:0:0"+"\r\n";

    text=Str_to_Binary(text);
    text=Cod( text);
    text=Binary_to_Str( text);

    SaveArchivo(text);
}

void deleteUSer(QString user)
{
    string text;
    string text_new;

    text=LeerArchivo();
    text=Str_to_Binary(text);
    text=decod( text);
    text=Binary_to_Str( text);

    qDebug() << QString::fromStdString(text);

    // int posUSer_initial=existUser(user);
    int posUSer_initial= text.find(user.toStdString());

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
    qDebug() << QString::fromStdString(text_new);

    text_new=Str_to_Binary(text_new);
    text_new=Cod( text_new);
    text_new=Binary_to_Str( text_new);

    SaveArchivo(text_new);
}

void deleteScore(QString user)
{

    string text;
    string text_new;


        text=LeerArchivo();
        text=Str_to_Binary(text);
        text=decod( text);
        text=Binary_to_Str( text);

        qDebug() << QString::fromStdString(text);

        string score="\r\n0:0:0\r\n0:0:0\r\n0:0:0\r\n0:0:0\r\n";
        //int posUser=existUser(user);
        int posUser = text.find(user.toStdString());

        int posPass_initial=text.find("\n",posUser);
        int posPass_final=0;
        int aux=posPass_initial+1;

        for (int i=0;i<4 ;) {
            posPass_final=text.find('\n',aux);
            aux= posPass_final+1;
            i+=1;
        }
        aux = text.find('\n',aux);
        if(aux==-1) text_new=text.substr(0,posPass_initial-1)+score;
        else {
            text_new=text.substr(0,posPass_initial-1)+score+text.substr(posPass_final+1);
        }

        qDebug() << QString::fromStdString(text_new);

        text_new=Str_to_Binary(text_new);
        text_new=Cod( text_new);
        text_new=Binary_to_Str( text_new);

        SaveArchivo(text_new);

}

void GoScore(QString user,QString Score,int level){

    string text;
    string text_new;

    string score = Score.toStdString();
    text=LeerArchivo();
    text=Str_to_Binary(text);
    text=decod( text);
    text=Binary_to_Str( text);

    qDebug() << QString::fromStdString(text);

    //int posUser=existUser(user);
    int pos_initial = text.find(user.toStdString());
    int pos_final=0;
    int aux=pos_initial;

    for (int i=0;i<=level ;) {
        pos_initial=text.find('\n',aux);
        aux= pos_initial+1;
        i+=1;
    }

    pos_final= text.find('\n', pos_initial+1);

    string mod=text.substr(aux,((pos_final-1)-aux));

    qDebug() << QString::fromStdString(mod);

    string a,b,c;

    int pScore=mod.find(":");
    //pScore+=1;
    int pScore_final=mod.find(":", pScore+1);

    a=mod.substr(0,pScore);
    b=mod.substr(pScore+1,pScore_final-pScore-1);
    c=mod.substr(pScore_final+1);

    qDebug() <<QString::fromStdString(a)<<QString::fromStdString(b)<<QString::fromStdString(c);

    int a_ =stoi(a);
    int b_ =stoi(b);
    int c_ =stoi(c);
    int score_=stoi(score);

    if(score_>c_) c = score;
    if(score_>b_){
        c = b;
        b = score;
    }
    if(score_ > a_){
        b = a;
        a = score;
    }

    qDebug() <<QString::fromStdString(a)<<QString::fromStdString(b)<<QString::fromStdString(c);
    text_new = text.substr (0, pos_initial-1) + "\r\n" + a+":"+b+":"+c + text.substr (pos_final-1);

    qDebug() << QString::fromStdString(text_new);

    text_new=Str_to_Binary(text_new);
    text_new=Cod( text_new);
    text_new=Binary_to_Str( text_new);

    SaveArchivo(text_new);
}

bool CheckLevel(QString user, int level)
{
    if(level == 1) return true;

    string text;
    string text_new;

    text=LeerArchivo();
    text=Str_to_Binary(text);
    text=decod( text);
    text=Binary_to_Str( text);

    int posUser_initial = text.find(user.toStdString());
    posUser_initial=text.find('\n',posUser_initial)+1;

    if(level == 2 and text.at(posUser_initial) == '1') return true;

    else if(level == 3 and text.at(posUser_initial+2) == '1') return true;

    return false;
}
void UpdateLevel(QString user, int level)
{
    string text;
    string text_new;

    text=LeerArchivo();
    text=Str_to_Binary(text);
    text=decod( text);
    text=Binary_to_Str( text);

    qDebug() << QString::fromStdString(text);

    int pos_initial = text.find (user.toStdString());
    pos_initial=text.find('\n',pos_initial)+1;

    int pos_final = text.find('\n',pos_initial);

    if(level==1) text_new = text.substr (0, pos_initial) + "1:0:0"+text.substr (pos_final-1);

    else if(level==2) text_new = text.substr (0, pos_initial) + "1:1:0"+text.substr (pos_final-1);

    else {
        text_new = text.substr (0, pos_initial) + "1:1:1"+text.substr (pos_final-1);
    }

    qDebug() << QString::fromStdString(text_new);

    text_new=Str_to_Binary(text_new);
    text_new=Cod(text_new);
    text_new=Binary_to_Str( text_new);

    SaveArchivo(text_new);
}

bool ValidUandP(QString user_pass)
{
    for(int i=0;i<=user_pass.length();i+=1){
        if(user_pass.at(i)=='\n' or user_pass.at(i)==":" or user_pass.at(i)=='\r'){
            return false;
        }
    }
    return true;
}

bool existUser(QString user)
{
    qDebug() << "Comprobar usuario";
    string texto,user_;
    texto=LeerArchivo();
    texto=Str_to_Binary(texto);
    texto=decod(texto);
    texto=Binary_to_Str(texto);

    qDebug() << texto.length();

    int exist=texto.find(user.toStdString());
    if (exist == -1) return false;
    qDebug() << exist;
    user_ = texto.substr(exist,user.length());
    qDebug() << QString::fromStdString(user_) << " = " << user;

    if(user.toStdString() == user_) return true;
    return false;

}
bool CheckPassword(QString user, QString password){

    qDebug() << "Comprobar contraseña";
    string texto;

    texto=LeerArchivo();
    texto=Str_to_Binary(texto);
    texto=decod(texto);
    texto=Binary_to_Str(texto);

    qDebug() << QString::fromStdString(texto);

    //int posUser=existUser(user);
    int posUser = texto.find(user.toStdString());
    int end = texto.find("\r",posUser);
    qDebug() << posUser;
    qDebug() << end;

    posUser=posUser+user.length();
    qDebug() << posUser;

    string check = texto.substr(posUser+1,end-posUser-1);

    qDebug() << QString::fromStdString(check) << " = " << password;

    if(password.toStdString() == check) return true;
    return false;
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

vector<string> usersName()
{
    string text;
    text=LeerArchivo();
    text=Str_to_Binary(text);
    text=decod( text);
    text=Binary_to_Str( text);

    vector <string> users;

    qDebug() << QString::fromStdString(text);

    int posI=text.find('\n')+1;
    int posJ=text.find(':',posI);
    int aux=posI;
    users.push_back(text.substr(posI,posJ-posI));

    while(aux!=-1){
        for(int i=0;i<=4;i+=1){

            posI=text.find('\n',aux);
            aux=posI+1;

        }
        if(aux>=int(text.size()))aux=-1;
        else if(aux!=int(text.size())){

            posJ=text.find(':',aux);

            users.push_back(text.substr(aux,posJ-aux));}
    }

    for(auto i = users.begin();i!=users.end();i++){
        qDebug() << QString::fromStdString(*i);
    }
    return users;
}

vector<string> playerScore(QString user_)
{
    string text;
    text=LeerArchivo();
    text=Str_to_Binary(text);
    text=decod( text);
    text=Binary_to_Str( text);

    //string user= user_.tostdstring();

    vector <string> score;

    int posI=text.find(user_.toStdString());


    int posJ;
    int aux=posI;

    for(int i=0;i<2;i+=1){

        posI=text.find('\n',aux);
        aux=posI+1;

    }
    posI = aux;
    for(int i=0;i<3;i+=1){
        for(short i=0;i<3;i++){
            if(i==2)
                posJ = text.find('\r',aux);
            else
                posJ = text.find(':',aux);
            score.push_back(text.substr(posI,posJ-posI));
            posI = posJ+1;
            aux = posI;
        }
        posI = posJ += 2;
        aux = posI;

//        posJ=text.find('\n',aux);

//        score.push_back(text.substr(posI+1,posJ-1-posI-1));

//        posI=text.find('\n',aux);

//        aux=posI+1;
    }

    for(auto i=score.begin();i!=score.end();i++)
        qDebug() << QString::fromStdString(*i);

    return score;
}
