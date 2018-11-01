#ifndef NO_HPP
#define NO_HPP


using namespace std;
template <typename T>
class Arvore;

template <typename T>
class No {
private:
    T valor;
    No<T>* Esqr;
    No<T>* Dirt;
    No<T>* anterior;
    No(T Valor): valor(Valor), Esqr(nullptr),Dirt(nullptr),anterior(nullptr){
    }
public:
    string getValor(){
        return *valor;
    }

    T getonlyValor(){
        return valor;
    }

    T operator*(){
        return getValor();
    }

    friend class Arvore<T>;
};



#endif //ARVORE_AVL_NO_HPP
