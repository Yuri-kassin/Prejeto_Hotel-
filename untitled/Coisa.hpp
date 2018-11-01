#ifndef COISA_HPP
#define COISA_HPP


class Coisa {

private:
    string primnome;
    string ultnome;
    string idade;
    string RG;
    string dias;
    string check;
    string quarto;
public:
    Coisa(string primnome,string ultnome,string idade,string RG,string dias){
        this->primnome = primnome;
        this->ultnome = ultnome;
        this->idade = idade;
        this->RG = RG;
        this->dias = dias;
        quarto = "00";
        check = "0";
    }

    string getPrimNome(){
        return primnome;
    }

    string getUltnome(){
        return ultnome;
    }
    string getIdade(){
        return idade;
    }

    string getRG(){
        return RG;
    }

    string getDias(){
        return dias;
    }

    string getCheck(){
        return check;
    }
    string getQuarto(){
        return quarto;
    }

    void setCheck(string check){
        this->check = check;
    }

    void setQuarto(string quarto){
        this->quarto = quarto;
    }



    bool operator < (const Coisa& Coisa2) const
    {
        return (primnome < Coisa2.primnome);
    }

    bool operator > (const Coisa& Coisa2) const
    {
        return (primnome > Coisa2.primnome);
    }

    bool operator <= (const Coisa& Coisa2) const
    {
        return (primnome <= Coisa2.primnome);
    }

    bool operator >= (const Coisa& Coisa2) const
    {
        return (primnome <= Coisa2.primnome);
    }

    bool operator == (const Coisa& Coisa2) const
    {
        return (primnome == Coisa2.primnome);
    }
    bool operator != (const Coisa& Coisa2) const
    {
        return (primnome != Coisa2.primnome);
    }

//    bool operator == (string n, const Coisa)
//    {
//        return (n == Coisa.nome);
//    }
    string operator *()
    {
        return primnome;
    }

//    bool operator = (const Coisa& Coisa2) const
//    {
//        return (nome = Coisa2.nome);
//    }

};


#endif //ARVORE_AVL_COISA_HPP
