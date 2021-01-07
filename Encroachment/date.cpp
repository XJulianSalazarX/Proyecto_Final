#include "date.h"

date::date()
{

}

void date::adduser(QString user, QString password)
{
 string user_=user.toStdString();
 string password_=password.toStdString();

 string text="";
 text=LeerArchivo(); //????

}

string LeerArchivo()
{
    string archivo=":/data/users.dat";
    string texto="",linea="";
    fstream lectura;
    lectura.open(archivo,fstream::in|fstream::binary);

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
    string archivo=":/data/users.dat";
    fstream archivobinario;
    archivobinario.open(archivo,fstream::out|fstream::binary);
    archivobinario<<texto;
    archivobinario.close();
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
string Str_to_Binary(string texto)
{

   string binario;
    for(unsigned long long int i=0; i<texto.length(); i++){
        for(int j=0;j<8;j++) binario.push_back(char((((texto[i]<<j)&(0x80))/128)+48));
    }
    return binario;
}

string Cod( string bin){
    string bincod;
    int n=4;
    for (int i=0;i<n ;i++ ) {
        if (bin.size()==bincod.size()) break;

        if(bin[i]==49) bincod=bincod + '0';
        else {
            bincod=bincod + '1';
        }
    }

    float j=0;
    int cont0=0,cont1=0;

    while (j+n<bin.size()) {
        int con=0;


        for (int  k=0;k<n ;k++,j++ ) {
            if(bin[j]==48) cont0+=1;
            if(bin[j]==49) cont1+=1;

        }




        if(cont0>cont1){
            for (int num=0;num<n ;j++,num++ ) {



                if (bin.size()==bincod.size()) break;
                if (con==1) {
                    if(bin[j]==49) bincod=bincod + '0';
                    else {
                        bincod=bincod + '1';
                    }
                    con=0;

                }
                else{
                    bincod=bincod + bin[j];
                    con=con+1;}
            }
            j=j-n;
        }
        if(cont0<cont1){
            for (int num=0;num<n ;j++,num++ ) {
                if (bin.size()==bincod.size()) break;


                if (con==2) {
                    if(bin[j]==49) bincod=bincod + '0';
                    else {
                        bincod=bincod + '1';
                    }
                    con=0;

                }
                else{
                    bincod=bincod + bin[j];
                    con=con+1;
                }
            }
            j=j-n;
        }
        if(cont0==cont1){
            for (int num=0;num<n ;j++,num++ ) {

                if (bin.size()==bincod.size()) break;

                if(bin[j]==49) bincod=bincod + '0';
                else {
                    bincod=bincod + '1';
                }
            }
            j=j-n;
        }
        cont0=0;
        cont1=0;

    }

    return bincod;

}

string decod( string bin){
    int n=4;
    string bincod;
    for (int i=0;i<n ;i++ ) {
        if (bin.size()==bincod.size()) break;

        if(bin[i]==49) bincod=bincod + '0';
        else {
            bincod=bincod + '1';
        }
    }

    float j=0;
    int cont0=0,cont1=0;

    while (j+n<bin.size()) {
        int con=0;


        for (int  k=0;k<n ;k++,j++ ) {
            if(bincod[j]==48) cont0+=1;
            if(bincod[j]==49) cont1+=1;

        }
        if(cont0==cont1){
            for (int num=0;num<n ;j++,num++ ) {

                if (bin.size()==bincod.size()) break;

                if(bin[j]==49) bincod=bincod + '0';
                else {
                    bincod=bincod + '1';
                }
            }
            j=j-n;
        }
        if(cont0>cont1){
            for (int num=0;num<n ;j++,num++ ) {



                if (bin.size()==bincod.size()) break;
                if (con==1) {
                    if(bin[j]==49) bincod=bincod + '0';
                    else {
                        bincod=bincod + '1';
                    }
                    con=0;

                }
                else{
                    bincod=bincod + bin[j];
                    con=con+1;}
            }
            j=j-n;
        }
        if(cont0<cont1){
            for (int num=0;num<n ;j++,num++ ) {
                if (bin.size()==bincod.size()) break;

                if (con==2) {
                    if(bin[j]==49) bincod=bincod + '0';
                    else {
                        bincod=bincod + '1';
                    }
                    con=0;
                }
                else{
                    bincod=bincod + bin[j];
                    con=con+1;
                }
            }
            j=j-n;
        }

        cont0=0;
        cont1=0;

    }

    return bincod;

}
