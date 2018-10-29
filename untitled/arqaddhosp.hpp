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
public:
    ArqAddHosp(string Nome, string Idade, string RG){
        this->Nome = Nome;
        this->Idade = Idade;
        this->RG = RG;
        Gravar();
    }
    void Gravar(){
        ofstream arq;
        arq.open("aquivo.txt");
  //      arq<<Nome<<" "<<Idade<<" "<<RG<<" "<<endl;
        arq.close();
        cout<<"kkk eae man"<<endl;
    }
};

#endif // ARQADDHOSP_HPP
