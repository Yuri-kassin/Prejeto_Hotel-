#ifndef ARQADDHOSP_HPP
#define ARQADDHOSP_HPP
#include<iostream>
#include<fstream>
#include<iostream>

using namespace std;
class ArqAddHosp
{
private:
    string Nome;
    string Idade;
    string RG;
    string sobrenome;
    int dia;
public:
    ArqAddHosp(string Nome, string Idade, string RG,string sobrenome, int dia){
        this->Nome = Nome;
        this->Idade = Idade;
        this->RG = RG;
        this->sobrenome = sobrenome;
        this->dia = dia;
        Gravar();
    }
    void Gravar(){
        ofstream arq;
        arq.open("aquivo.txt",ios::app);
        arq<<Nome<<" "<<Idade<<" "<<RG<<" "<<0<<endl;
        arq.close();
        cout<<"kkk eae man"<<endl;
    }
};

#endif // ARQADDHOSP_HPP
